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
	void processBuffer(FormatData& format_data, unsigned char* buffer, int bufferSize);
	Echo(int delay);
	Echo();
	int getDelay();
	virtual ~Echo();
	void setDelay(int newDelay);
};

