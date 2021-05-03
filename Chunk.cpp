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

void ChunkInterface::print()
{
	std::cout << "ID: " << chunkName() << " Size: " << chunk_header.chunk_size << std::endl;
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
		throw std::runtime_error("Not List Chunk");
	}
	data.resize(chunkSize());
	file.read((char*)data.data(), data.size());
}

void ListChunk::print()
{
	std::cout << "List Chunk: " << " Data Size: " << chunkSize() << " bytes" << " Data: " << std::string{(char*)data.data(), data.size()} << std::endl;
}

ChunkInterface::Type ListChunk::type()
{
	return Type::list;
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