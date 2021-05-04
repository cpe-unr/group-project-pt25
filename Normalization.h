/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#pragma once

#include <cstdint>
#include <cmath>
#include"Processor.h"


class Normalizer : public Processor
{
public:
	Normalizer();
	Normalizer(double amplitude);
	void processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize) override;
	void processBufferSixteen(FormatData& format_data, unsigned short* buffer, int bufferSize) override;
	double getAmp();
	void setAmp(double amplitude);
	virtual ~Normalizer();
private:
	double amplitude;
};
