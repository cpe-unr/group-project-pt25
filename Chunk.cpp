/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#include <iostream>
#include "Chunk.h"

std::string ChunkHeader::chunkName()
{
	return std::string {chunk_id, 4};
}

ChunkInterface::ChunkInterface()
{
	chunk_header.chunk_id[0] = '\0';
	chunk_header.chunk_size = 0;
}

ChunkInterface::ChunkInterface(const ChunkHeader& header)
: chunk_header(header)
{}

std::string ChunkInterface::chunkName()
{
	return chunk_header.chunkName();
}

std::size_t ChunkInterface::chunkSize()
{
	return chunk_header.chunk_size;
}

void ChunkInterface::write(std::ofstream &file)
{
	file.write((char*)&chunk_header, sizeof(chunk_header));
}

void ChunkInterface::print()
{
	std::cout << "ID: " << chunkName() << " Size: " << chunk_header.chunk_size << std::endl;
}

std::uint32_t ChunkInterface::writeSize()
{
	return sizeof(ChunkHeader);
}

//************************FORMAT CHUNK

FormatChunk::FormatChunk(const ChunkHeader& header, std::ifstream& file)
: ChunkInterface(header)
{
	if(chunkName() != "fmt ")
	{
		throw std::runtime_error("Not Format Chunk");
	}
	file.read((char*)&data, sizeof(data));
}

void FormatChunk::print()
{
	std::cout << "Audio Format: " << data.audio_format
		<< " Number of Channels: " << data.num_channels
		<< " Sample Rate: " << data.sample_rate
		<< " Byte Rate: " << data.byte_rate
		<< " Sample Alignment: " << data.sample_alignment
		<< " Bit Depth: " << data.bit_depth
		<< std::endl;
}

ChunkInterface::Type FormatChunk::type()
{
	return Type::format;
}

void FormatChunk::write(std::ofstream &file)
{
	ChunkInterface::write(file);
	file.write((char*)&data, sizeof(data));
}

std::uint32_t FormatChunk::writeSize()
{
	return ChunkInterface::writeSize() + sizeof(FormatData);
}

void FormatChunk::writeCSV(std::ofstream &file)
{
	file << data.audio_format << ','
		<< data.num_channels << ','
		<< data.sample_rate << ','
		<< data.byte_rate << ','
		<< data.sample_alignment << ','
		<< data.bit_depth;
}

FormatData FormatChunk::formatData()
{
	return data;
}

//************************DATA CHUNK

DataChunk::DataChunk(const ChunkHeader& header, std::ifstream& file)
: ChunkInterface(header)
{
	if(chunkName() != "data")
	{
		throw std::runtime_error("Not Data Chunk");
	}
	data.resize(chunkSize());
	file.read((char*)data.data(), data.size());
}

void DataChunk::print()
{
	std::cout << "Data Size: " << data.size() << " bytes" << std::endl;
}

ChunkInterface::Type DataChunk::type()
{
	return Type::data;
}

void DataChunk::write(std::ofstream &file)
{
	ChunkInterface::write(file);
	file.write((char*)data.data(), data.size());
}

std::uint32_t DataChunk::writeSize()
{
	return ChunkInterface::writeSize() + data.size();
}

void DataChunk::writeCSV(std::ofstream &)
{}

BufferData DataChunk::bufferData()
{
	BufferData buffer_data;
	buffer_data.size = data.size();
	buffer_data.buffer = data.data();
	return buffer_data;
}

//************************LIST CHUNK

ListChunk::ListChunk(const ChunkHeader& header, std::ifstream& file)
: ChunkInterface(header)
{
	if(chunkName() != "LIST")
	{
		throw std::runtime_error("No List Chunk");
	}
	int counter = chunkSize();
	if(counter > 4)
	{
		//Create a string buffer to read INFO header
		std::string info;
		info.resize(4);
		file.read((char*)info.data(), info.size());
		if(info != "INFO")
		{
			throw std::runtime_error("No Metadata Found");
		}
		counter -= 4;
		while(counter > sizeof(ChunkHeader))
		{
			//Read the subchunk header
			ChunkHeader sub_chunk_header;
			file.read((char*)&sub_chunk_header, sizeof(sub_chunk_header));
			counter -= sizeof(sub_chunk_header);
			//Read the metadata from the file and add to subchunk array
			if(counter >= sub_chunk_header.chunk_size)
			{
				std::string metadata_id {sub_chunk_header.chunk_id, sizeof(sub_chunk_header.chunk_id)};
				std::string metadata;
				metadata.resize(sub_chunk_header.chunk_size);
				file.read((char*)metadata.data(), metadata.size());
				metadata.pop_back(); //Remove extra trailing null terminator read into string
				counter -= metadata.size();
				//Save the subchunk data
				subchunks.push_back(SubChunk {metadata_id, metadata});
			}
			else
			{
				//Failsafe if the data is incorrect
				counter = 0;
			}
		}
	}
}

void ListChunk::print()
{
	std::cout << "List Chunk: " << chunkSize() << " bytes" << std::endl;
	for(auto &subchunk : subchunks)
	{
		std::cout <<  "ID: " << subchunk.metadata_id << " Data: " << subchunk.metadata << std::endl;
	}
}

ChunkInterface::Type ListChunk::type()
{
	return Type::list;
}

void ListChunk::setMetadata(const std::string &tag, const std::string &metadata)
{
	auto subchunk = find(tag);
	if(subchunk != nullptr)
	{
		//Just update the existing subchunk data
		subchunk->metadata = metadata;
	}
	else
	{
		//Add new subchunk data
		subchunks.push_back(SubChunk {tag, metadata});
	}
	//Update list chunk header for possible changes in subchunk lengths
	//Adds Subchunks plus four bytes for the "INFO" tag
	chunk_header.chunk_size = writeSubchunkSize() + 4;
}

void ListChunk::write(std::ofstream &file)
{
	ChunkInterface::write(file);
	file.write("INFO", 4);
	for(auto &subchunk : subchunks)
	{
		file.write(subchunk.metadata_id.data(), subchunk.metadata_id.size());
		std::uint32_t size = subchunk.metadata.size() + 1; //Plus one for null terminator
		file.write((char*)&size, sizeof(uint32_t));
		file.write(subchunk.metadata.c_str(), subchunk.metadata.size() + 1); //Plus one for null terminator
	}
}

//Returns the number of bytes to be written for the subchunks
std::uint32_t ListChunk::writeSubchunkSize()
{
	//Count the size of the subchunks not including the "INFO"
	std::uint32_t result = 0;
	for(auto &subchunk : subchunks)
	{
		//Size of the subchunk header plus the metadata
		result += sizeof(ChunkHeader) + subchunk.metadata.size() + 1; //Plus one for null terminator
	}
	return result;
}

std::uint32_t ListChunk::writeSize()
{
	//Set the initial size to the chunk header size plus the tag "INFO"
	std::uint32_t result = ChunkInterface::writeSize() + 4 + writeSubchunkSize();
	return result;
}

void ListChunk::writeCSV(std::ofstream &file)
{
	for(auto &subchunk : subchunks)
	{
		file << subchunk.metadata << ' ';
	}
}

SubChunk* ListChunk::find(const std::string &tag)
{
	for(auto &subchunk : subchunks)
	{
		if(subchunk.metadata_id == tag)
		{
			return &subchunk;
		}
	}
	return nullptr;
}

//************************UNKOWN CHUNK

UnknownChunk::UnknownChunk(const ChunkHeader& header, std::ifstream& file)
: ChunkInterface(header)
{
	data.resize(chunkSize());
	file.read((char*)data.data(), data.size());
}

void UnknownChunk::print()
{
	std::cout << "Unkown Chunk: " << chunkName() << " Data Size: " << chunkSize() << " bytes" << std::endl;
}

ChunkInterface::Type UnknownChunk::type()
{
	return Type::unknown;
}

void UnknownChunk::write(std::ofstream &file)
{
	ChunkInterface::write(file);
	file.write((char*)data.data(), data.size());
}

std::uint32_t UnknownChunk::writeSize()
{
	return ChunkInterface::writeSize() + data.size();
}

void UnknownChunk::writeCSV(std::ofstream &)
{}