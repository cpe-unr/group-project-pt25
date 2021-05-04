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
	 * parameterized constructor for Echo class
	 * @param delay
	 */

	Echo(int delay);

	/**
	 * constructor for Echo class
	 */

	Echo();

	/**
	 * Getter for the delay attribute of Echo class
	 * @return
	 */

	int getDelay();

	/**
	 * Destructor for Echo class
	 */

	virtual ~Echo();

	/**
	 * Setter for the delay attribute of Echo class
	 * @param newDelay
	 */

	void setDelay(int newDelay);
};

