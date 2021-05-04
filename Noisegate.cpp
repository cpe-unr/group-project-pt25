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

void NoiseGate::processBuffer(FormatData& format_data, unsigned char* buffer, int bufferSize)
{
	if(format_data.bit_depth == 8)
	{
		if (format_data.num_channels == 2)
		{
			//stereo 8 bit
			/*
			for(int i = 0; i < sizeLeft-1; i++)
			{
				if(bufferLeft[i]*amplitude < 129*amplitude)
				{
					 bufferLeft[i] = 128;
				}
			}

			for(int i = 0; i < sizeRight-1; i++)
			{
				if(bufferRight[i]*amplitude < 129*amplitude)
				{
					 bufferRight[i] = 128;
				}

			} */
		}
		else if(format_data.num_channels == 1)
		{
			//mono 8 bit
			for(int i = 0; i < bufferSize-1; i++)
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
	else if(format_data.bit_depth == 16)
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
			//mono 16 bit
			for(int i = 0; i < bufferSize-1; i++)
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
	else
	{
		std::cout << "Improper bit depth" << std::endl;
	}
}

double NoiseGate::getAmp(){
	return amplitude;
}
void NoiseGate::setAmp(double nAmplitude){
	amplitude = nAmplitude;
}