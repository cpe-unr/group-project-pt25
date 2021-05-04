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

void Echo::processBuffer(FormatData& format_data, unsigned char* buffer, int bufferSize)
{
 
 
	if(format_data.bit_depth == 8)
	{
		if(format_data.num_channels == 2)
		{
			//Echo processor for 8 Bit stereo
			/*
			int cDelay = delay;
		for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
			if((bufferLeft[bufferIndex]) > 110){
			}
			else{
				bufferLeft[bufferIndex] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-cDelay];
			}
		}

		for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
			if((bufferRight[bufferIndex]) > 110){
			}
			else{
				bufferRight[bufferIndex] = bufferRight[bufferIndex] + bufferRight[bufferIndex-cDelay];
			}
		} */
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
	else if(format_data.bit_depth == 16)
	{	
	
		if(format_data.num_channels == 2)
		{
			/*
			//Echo processor for 16 bit stereo
			int cDelay = delay;
				for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
					if((bufferLeft[bufferIndex]) > 14090){
					}
					else{
						bufferLeft[bufferIndex] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-cDelay];
					}
				}
				for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
					if((bufferRight[bufferIndex]) > 14090){
					}
					else{
						bufferRight[bufferIndex] = bufferRight[bufferIndex] + bufferRight[bufferIndex-cDelay];
					}
				} */
		}
		else if(format_data.num_channels == 1)
		{
			//Echo processor for 16 bit mono
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
	else
	{
		std::cout << "Improper bit depth" << std::endl;
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
