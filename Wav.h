/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include <string>
#include <vector>
#include "Chunk.h"
#include "WavHeader.h"

class Wav
{
	public:
		Wav();
		Wav(const std::string &file_name);
		~Wav();

		FormatData formatData();
		BufferData bufferData();
		void readFile(const std::string &file_name);
		void saveAs(const std::string &file_name);
		std::string fileName();
		void print();
		void writeCSV();

	private:
		std::string file_name;
		WavHeader wav_header;
		std::vector<ChunkInterface*> chunks;

		void clear();
		template<typename C> C* find(ChunkInterface::Type type);
		ChunkInterface* readChunk(std::ifstream &file);
		void readWavFile(std::ifstream &file);
		std::uint32_t writeSize();
};

//Convenience function to find specific wave chunk data
template<typename C> C* Wav::find(ChunkInterface::Type type)
{
	for(auto chunk : chunks)
	{
		if(chunk->type() == type)
		{
			return reinterpret_cast<C*>(chunk);
		}
	}
	return nullptr;
}