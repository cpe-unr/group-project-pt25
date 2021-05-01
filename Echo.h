#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Echo: public Processor {	   
public:
	int delay = 20000;
	void Echo::processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight);
	void Echo::processBuffer16Bitmono(unsigned char* buffer, int bufferSize);
	void Echo::process8BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight);
	void Echo::processBuffer8bitMono(unsigned char* buffer, int bufferSize);
	Echo(int delay);
	Echo();
	int Echo::getDelay();
	virtual ~Echo();
	void setDelay(int newDelay);
};
#endif //ECHO_H
