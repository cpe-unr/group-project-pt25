#include"Echo.h"
#include"Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include "NoiseGate.h"

void NoiseGate::processBuffer(unsigned char* buffer, int bufferSize)
{
	int yes = NoiseGate::index;
	for(yes; yes <= bufferSize; yes++)
	{
		if(buffer[yes] <= 131 && buffer[yes] >= 125){
			buffer[yes] = 128;
		}
	}

}
NoiseGate::NoiseGate()
{
}
NoiseGate::~NoiseGate()
{
}
