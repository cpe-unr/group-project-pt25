/*
#pragma once

#include <string>
#include <vector>

#include "wavheader.h"

class Wav{
protected:
    int bufferSize_data;
    unsigned char* buffer = NULL;
    std::vector <SubChunkData> metadata;
    wavHeader wave_Header;
    dataChunk data_Chunk;
    FMT fmt;
public:
    wavHeader getwavHeader();
    unsigned char *getBuffer();
    int getBufferSize();
    void readFile(const std::string &filename);
    void writeFile(const std::string &outFilename);
    ~Wav();
};
*/