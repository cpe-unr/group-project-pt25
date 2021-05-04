/*
 * Authors: Kurtis LeMay, Amaan Sidhu, Matthew Devine
 * Date: May 2, 2021
 * Assignment: Semester Project
*/

#include <fstream>
#include <iostream>
#include <string>
#include "Echo.h"
#include "Noisegate.h"
#include "Processor.h"
#include "Wav.h"

NoiseGate::NoiseGate()
{
	amplitude = 0;
}

NoiseGate::NoiseGate(double amplitude) : amplitude(amplitude)
{
	
}

NoiseGate::~NoiseGate()
{
	
}

void NoiseGate::processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize)
{
	if(format_data.num_channels == 2)
	{
		//NoiseGate processor for 8 Bit stereo
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
			if(bufferL[i]*amplitude < 129*amplitude)
				{
					 bufferL[i] = 128;
				}
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			if(bufferR[i]*amplitude < 129*amplitude)
				{
					 bufferR[i] = 128;
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
		//NoiseGate processor for 8 bit mono
		for(int i = 0; i < bufferSize; i++)
		{
			if(buffer[i]*amplitude < 129*amplitude)
				{
				 	buffer[i] = 128;
				}
		}
	}
	else
	{
		std::cout << "Improper number of audio channels" << std::endl;
	}
}	

void NoiseGate::processBufferSixteen(FormatData& format_data, short* buffer, int bufferSize)
{
	if(format_data.num_channels == 2)
	{
		//stereo 16 bit	
			/*
			for(int i = 0; i < sizeLeft-1; i++)
			{
				if(bufferLeft[i]*amplitude < 16385*amplitude)
				{
				 	bufferLeft[i] = 0;
				}
			}

			for(int i = 0; i < sizeRight-1; i++)
			{
				if(bufferRight[i]*amplitude < 16385*amplitude)
				{
					bufferRightbufferRight[i] = 0;
				}
			} */
	}
	else if(format_data.num_channels == 1)
	{
		//NoiseGate processor for 16 bit mono
		for(int i = 0; i < bufferSize; i++)
		{
			if(buffer[i]*amplitude < 16385*amplitude)
				{
					 buffer[i] = 0;
				}
		}
	}
	else
	{
		std::cout << "Improper number of audio channels" << std::endl;
	}
}

double NoiseGate::getAmp(){
	return amplitude;
}

void NoiseGate::setAmp(double nAmplitude){
	amplitude = nAmplitude;
}