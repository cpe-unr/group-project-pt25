/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Echo: public Processor {	   
public:
	int delay;
	void processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize) override;
	void processBufferSixteen(FormatData& format_data, unsigned short* buffer, int bufferSize) override;
	Echo(int delay);
	Echo();
	int getDelay();
	virtual ~Echo();
	void setDelay(int newDelay);
};

