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

	/**
	 * constructor for NoiseGate class
	 */

	NoiseGate();

	/**
	 * parameterized constructor for NoiseGate class
	 * @param amplitude
	 */

	NoiseGate(double amplitude);

	/**
	 * Used to pass the buffer from function to function for 8-bit audio processing
	 * @param format_data
	 * @param buffer
	 * @param buffersize
	 */

	void processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize) override;

	/**
	 * Used to pass the buffer from function to function for 16-bit audio processing
	 * @param format_data
	 * @param buffer
	 * @param buffersize
	 */

	void processBufferSixteen(FormatData& format_data, unsigned short* buffer, int bufferSize) override;

	/**
	 * Getter for the amplitude attribute of NoiseGate class
	 * @return
	 */

	double getAmp();

	/**
	 * Setter for the amplitude attribute of NoiseGate class
	 * @param amplitude
	 */

	void setAmp(double amplitude);

	/**
	 * Destructor for NoiseGate class
	 */

	virtual ~NoiseGate();
private:
	double amplitude;
};