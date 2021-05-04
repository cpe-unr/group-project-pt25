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
#include "Normalization.h"
#include "Processor.h"
#include "Wav.h"

Normalizer::Normalizer()
{
	amplitude = 0;
}

Normalizer::Normalizer(double amplitude) : amplitude(amplitude)
{
	
}

Normalizer::~Normalizer()
{
	
}

void Normalizer::processBufferEight(FormatData& format_data, unsigned char* buffer, int bufferSize)
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
			bufferL[i] = bufferL[i]*amplitude;
		}
		for(int i = 0; i < halfBufferSize; i++)
		{
			bufferR[i] = bufferR[i]*amplitude;
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
			buffer[i] = buffer[i]*amplitude;
		}
	}
	else
	{
		std::cout << "Improper number of audio channels" << std::endl;
	}
}	

void Normalizer::processBufferSixteen(FormatData& format_data, unsigned short* buffer, int bufferSize)
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

double Normalizer::getAmp(){
	return amplitude;
}

void Normalizer::setAmp(double nAmplitude){
	amplitude = nAmplitude;
}
