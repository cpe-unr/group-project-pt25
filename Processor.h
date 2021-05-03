#pragma once

#include <cstdint>
#include <cmath>

class Processor {
public:
    virtual void processBuffer16Stereo(int bufferSizeL, int bufferSizeR, short* bufferL, short* bufferR) = 0;
    virtual void processBuffer16Mono( int bufferSize, short* buffer) = 0;
    virtual void processBuffer8Stereo(int bufferSizeL, int bufferSizeR, unsigned char* bufferL, unsigned char* bufferR) = 0;
    virtual void processBuffer8Mono(int bufferSize, unsigned char* buffer) = 0;
};

