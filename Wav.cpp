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
	WavHeader wav_header;
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
}

std::string Wav::fileName()
{
	return file_name;
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
	clear();
	for(ChunkInterface *chunk = readChunk(file); chunk != nullptr; chunk = readChunk(file))
	{	
		chunks.push_back(chunk);
		chunk->print();
	}
}