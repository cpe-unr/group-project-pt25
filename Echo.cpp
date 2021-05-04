
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

void Echo::processBuffer(FormatData&, unsigned char* buffer, int bufferSize)
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
			int cDelay = delay;
			for(int i = 0; i < bufferSize-1; i++)
			{
				if((buffer[i]) > 110)
				{

				}
				else
				{
					buffer[i] = buffer[i] + buffer[i-cDelay];
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
			int cDelay = delay;
			for (int i = 0; i <= bufferSize; i++)
			{
				if((buffer[i]) > 14090)
				{

				}
				else
				{
					buffer[i] = buffer[i] + buffer[i-cDelay];
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
