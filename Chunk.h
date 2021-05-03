/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include <fstream>
#include <string>
#include <vector>

struct ChunkHeader
{
	char chunk_id[4];
	std::uint32_t chunk_size;

	std::string chunkName();
};

class ChunkInterface
{
	public:
		enum class Type {unknown, format, data, list};

		ChunkInterface();
		ChunkInterface(const ChunkHeader&);
		virtual ~ChunkInterface() = default;
		std::string chunkName();
		std::size_t chunkSize();
		virtual void print() = 0;
		virtual Type type() = 0;
		virtual void write(std::ofstream &file);
		virtual std::uint32_t writeSize();
		virtual void writeCSV(std::ofstream &file) = 0;

	protected:
		ChunkHeader chunk_header;
};

//************************FORMAT CHUNK

struct FormatData
{
	std::uint16_t audio_format = 0; // Should be 1 for PCM. 3 for IEEE Float
    std::uint16_t num_channels = 0;
    std::uint32_t sample_rate = 0;
    std::uint32_t byte_rate = 0; // Number of bytes per second. sample_rate * num_channels * Bytes Per Sample
    std::uint16_t sample_alignment = 0; // num_channels * Bytes Per Sample
    std::uint16_t bit_depth = 0; // Number of bits per sample
};

class FormatChunk : public ChunkInterface
{
	public:
		FormatChunk(const ChunkHeader&, std::ifstream&);
		~FormatChunk() override = default;
		void print() override;
		Type type() override;
		void write(std::ofstream &file) override;
		std::uint32_t writeSize() override;
		void writeCSV(std::ofstream &file) override;
		FormatData formatData();
	
	private:
		FormatData data;
};

//************************DATA CHUNK

struct BufferData
{
	std::size_t size = 0;
	unsigned char *buffer = nullptr;
};

class DataChunk : public ChunkInterface
{
	public:
		DataChunk(const ChunkHeader&, std::ifstream&);
		~DataChunk() override = default;
		void print() override;
		Type type() override;
		void write(std::ofstream &file) override;
		std::uint32_t writeSize() override;
		void writeCSV(std::ofstream &file) override;
		BufferData bufferData();

	private:
		std::vector<unsigned char> data;
};

//************************LIST CHUNK

class ListChunk : public ChunkInterface
{
	public:
		ListChunk(const ChunkHeader&, std::ifstream&);
		~ListChunk() override = default;
		void print() override;
		Type type() override;
		void write(std::ofstream &file) override;
		std::uint32_t writeSize() override;
		void writeCSV(std::ofstream &file) override;
	
	private:
		std::vector<unsigned char> data;
};

//************************UNKNOWN CHUNK

class UnknownChunk : public ChunkInterface
{
	public:
		UnknownChunk(const ChunkHeader&, std::ifstream&);
		~UnknownChunk() override = default;
		void print() override;
		Type type() override;
		void write(std::ofstream &file) override;
		std::uint32_t writeSize() override;
		void writeCSV(std::ofstream &file) override;
	
	private:
		std::vector<unsigned char> data;
};