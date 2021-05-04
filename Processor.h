/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include <cstdint>
#include <cmath>
#include "Chunk.h"

class Processor {
public:
    virtual void processBufferEight(FormatData&, unsigned char* buffer, int bufferSize) = 0;
    virtual void processBufferSixteen(FormatData&, unsigned short* buffer, int bufferSize) = 0;
};
