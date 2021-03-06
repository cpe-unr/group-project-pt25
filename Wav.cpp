/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#include <iostream>
#include <exception>
#include <fstream>
#include "Wav.h"
#include "WavHeader.h"

Wav::Wav()
{}

Wav::Wav(const std::string &file_name)
: file_name(file_name)
{
	readFile(file_name);
}

Wav::~Wav()
{
	clear();
}

FormatData Wav::formatData()
{
	auto chunk = find<FormatChunk>(ChunkInterface::Type::format);
	return chunk != nullptr ? chunk->formatData() : FormatData{};
}

BufferData Wav::bufferData()
{
	auto chunk = find<DataChunk>(ChunkInterface::Type::data);
	return chunk != nullptr ? chunk->bufferData() : BufferData{};
}

void Wav::readFile(const std::string &input_file_name)
{
	//Clean up in case readFile() has already been called
	clear();
	file_name = input_file_name;
	
	//Read file data
    std::ifstream file(file_name,std::ios::binary | std::ios::in);

    if(file.is_open())
	{
        file.read((char*)&wav_header, sizeof(wav_header));
		if(std::string {wav_header.riff_header, 4} != "RIFF")
		{
			throw std::runtime_error("Not RIFF Format");
		}
		if(std::string {wav_header.wave_header, 4} != "WAVE")
		{
			throw std::runtime_error("Not WAVE Format");
		}
		readWavFile(file);
        file.close();
    }
	else
	{
		throw std::runtime_error("Could not read file");
	}
}

void Wav::setTitle(const std::string &title)
{
	auto list_chunk = find<ListChunk>(ChunkInterface::Type::list);
	if(list_chunk == nullptr)
	{
		//Todo: Create an empty list chunk if null
		std::cout << "Todo: No metadata to edit\n";
		return;
	}
	list_chunk->setMetadata("INAM", title);
}

void Wav::setArtist(const std::string &artist)
{
	auto list_chunk = find<ListChunk>(ChunkInterface::Type::list);
	if(list_chunk == nullptr)
	{
		//Todo: Create an empty list chunk if null
		std::cout << "Todo: No metadata to edit\n";
		return;
	}
	list_chunk->setMetadata("IART", artist);
}

void Wav::saveAs(const std::string &new_file_name)
{
	if(file_name != new_file_name)
	{
		std::ofstream file(new_file_name,std::ios::binary | std::ios::out);

		if(file.is_open())
		{
			wav_header.wav_size = writeSize();
			file.write((char*)&wav_header, sizeof(wav_header));
			for(auto chunk : chunks)
			{
				chunk->write(file);
			}
			file.close();
		}
		else
		{
			throw std::runtime_error("Could not write to file");
		}
	}
	else
	{
		throw std::runtime_error("Can't overwrite source file");
	}
}

std::string Wav::fileName()
{
	return file_name;
}

void Wav::print()
{
	std::cout << "File Name: " << file_name << std::endl;
	std::cout << "File Size: " << wav_header.wav_size << " bytes" << std::endl;
	for(auto chunk : chunks)
	{
		chunk->print();
	}
}

void Wav::appendCSV(const std::string &csv_file_name)
{
	if(file_name != csv_file_name)
	{
		std::ofstream file(csv_file_name, std::ios::app);

		if(file.is_open())
		{
			auto format_chunk = find<FormatChunk>(ChunkInterface::Type::format);
			if(format_chunk != nullptr)
			{
				format_chunk->writeCSV(file);
				file << ',';
			}
			else
			{
				throw std::runtime_error("Missing format data");
			}

			auto list_chunk = find<ListChunk>(ChunkInterface::Type::list);
			if(list_chunk != nullptr)
			{
				list_chunk->writeCSV(file);
			}
			else
			{
				file << "No metadata";
			}
			file << std::endl;
			file.close();
		}
		else
		{
			throw std::runtime_error("Could not write to file");
		}
	}
	else
	{
		throw std::runtime_error("Can't overwrite source file");
	}
}

void Wav::clear()
{
	for(auto chunk : chunks)
	{
		delete chunk;
	}
	chunks.clear();
	file_name.clear();
}

ChunkInterface* Wav::readChunk(std::ifstream &file)
{
	// Create the correct chunk type
	ChunkHeader chunk_header;
	file.read(reinterpret_cast<char*>(&chunk_header), sizeof(chunk_header));
	if(!file.eof())
	{
		if (chunk_header.chunkName() == "fmt ")
		{
			return new FormatChunk(chunk_header, file);
		}
		else if (chunk_header.chunkName() == "data")
		{
			return new DataChunk (chunk_header, file);
		}
		else if (chunk_header.chunkName() == "LIST")
		{
			return new ListChunk (chunk_header, file);
		}
		else
		{
			// The chunk is not recognized
			return new UnknownChunk (chunk_header, file);
		}
	}
	return nullptr;
}

void Wav::readWavFile(std::ifstream &file)
{
	for(ChunkInterface *chunk = readChunk(file); chunk != nullptr; chunk = readChunk(file))
	{	
		chunks.push_back(chunk);
	}
}

std::uint32_t Wav::writeSize()
{
	std::size_t result = sizeof(WavHeader) - 8;
	for(auto chunk : chunks)
	{
		result += chunk->writeSize();
	}
	return result;
}