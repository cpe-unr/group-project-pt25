/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#include <string>
#include <iostream>
#include "Echo.h"
#include "Wav.h"
#include "Processor.h"


Echo::Echo()
{

}
Echo::Echo(int delay) : delay(delay)
{
	
}
Echo::~Echo()
{
	
}

void Echo::processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize)
{
	if(format_data.num_channels == 2)
	{
		//Echo processor for 8 Bit stereo
		int i, j;
		int halfBufferSize = bufferSize / 2;
		std::vector<unsigned char> bufferL;
		std::vector<unsigned char> bufferR;
		bufferL.resize(halfBufferSize);
		bufferR.resize(halfBufferSize);
		for(i = 0, j = 0; j < bufferSize; i ++, j += 2)
		{
			bufferL[i] = buffer[j];
			bufferR[i] = buffer[j + 1];
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			if(i > delay)
			{
				bufferL[i] = (bufferL[i] * 0.7f) + ((bufferL[i - delay]) * 0.3f);
			}
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			if(i > delay)
			{
				bufferR[i] = (bufferR[i] * 0.7f) + ((bufferR[i - delay]) * 0.3f);
			}
		}
		for(i=0, j=0; j < bufferSize; i++, j += 2)
		{
			buffer[j] = bufferL[i];
			buffer[j + 1] = bufferR[i];
		}
	}
	else if(format_data.num_channels == 1)
	{
		//Echo processor for 8 bit mono
		for(int i = 0; i < bufferSize; i++)
		{
			if(i > delay)
			{
				buffer[i] = (buffer[i] * 0.7f) + ((buffer[i - delay]) * 0.3f);
			}
		}
	}
	else
	{
		std::cout << "Improper number of audio channels" << std::endl;
	}
}	

void Echo::processBufferSixteen(FormatData& format_data, unsigned short* buffer, int bufferSize)
{
	if(format_data.num_channels == 2)
	{
		
		//Echo processor for 16 bit stereo
		int i, j;
		int halfBufferSize = bufferSize / 2;
		std::vector<unsigned short> bufferL;
		std::vector<unsigned short> bufferR;
		bufferL.resize(halfBufferSize);
		bufferR.resize(halfBufferSize);
		for(i = 0, j = 0; j < bufferSize; i ++, j += 2)
		{
			bufferL[i] = buffer[j];
			bufferR[i] = buffer[j + 1];
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			if(i > delay)
			{
				bufferL[i] = (bufferL[i] * 0.7f) + ((bufferL[i - delay]) * 0.3f);
			}
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			if(i > delay)
			{
				bufferR[i] = (bufferR[i] * 0.7f) + ((bufferR[i - delay]) * 0.3f);
			}
		}
		for(i=0, j=0; j < bufferSize; i++, j += 2)
		{
			buffer[j] = bufferL[i];
			buffer[j + 1] = bufferR[i];
		}
	}
	else if(format_data.num_channels == 1)
	{
		//Echo processor for 16 bit mono
		for(int i = 0; i < (bufferSize); i++)
		{
			if(i > delay)
			{
				buffer[i] = (buffer[i] * 0.7f) + ((buffer[i - delay]) * 0.3f);
			}
		}
	}
	else
	{
		std::cout << "Improper number of audio channels" << std::endl;
	}
}

void Echo::setDelay(int newDelay)
{
	delay = newDelay;
}
int Echo::getDelay()
{
	return delay;
}
