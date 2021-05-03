/*
#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Echo: public Processor {	   
public:
	int delay;
	void processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight);
	void processBuffer16Bitmono(unsigned char* buffer, int bufferSize);
	void process8BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight);
	void processBuffer8bitMono(unsigned char* buffer, int bufferSize);
	Echo(int delay);
	Echo();
	int getDelay();
	virtual ~Echo();
	void setDelay(int newDelay);
};
#endif //ECHO_H
*/