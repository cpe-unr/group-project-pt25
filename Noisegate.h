/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include <cstdint>
#include <cmath>
#include"Processor.h"


class NoiseGate : public Processor
{
public:
	NoiseGate();
	NoiseGate(double amplitude);
	void processBuffer(FormatData& format_data, unsigned char* buffer, int bufferSize);
	double getAmp();
	void setAmp(double amplitude);
	virtual ~NoiseGate();
private:
	double amplitude;
};