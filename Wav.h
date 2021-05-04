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

		/**
		 * constructor for Wav class
		 */

		Wav();

		/**
		 * parameterized constructor for Wav class
		 * @param file_name
		 */

		Wav(const std::string &file_name);

		/**
		 * Destructor for Wav class
		 */

		~Wav();

		FormatData formatData();
		BufferData bufferData();

		/**
		 * Establishes an input file stream with the file the user states as a parameter
		 * @param file_name
		 */

		void readFile(const std::string &file_name);

		/**
		 * Sets the title of the .wav file in the metadata
		 * @param file_name
		 */

		void setTitle(const std::string &title);

		/**
		 * Sets the artist of the .wav file in the metadata
		 * @param file_name
		 */

		void setArtist(const std::string &title);

		/**
		 * Saves the processed buffer as a new .wav file in the name the user was prompted for as a parameter
		 * @param file_name
		 */

		void saveAs(const std::string &file_name);
		std::string fileName();
		void print();
		void appendCSV(const std::string &csv_file_name);

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
template<typename C>
C* Wav::find(ChunkInterface::Type type)
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