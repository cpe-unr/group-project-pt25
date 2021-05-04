#ifndef ECHO_H
#define ECHO_H

#include "Processor.h"
#include <cstdint>
#include <cmath>

class Echo: public Processor {	   
public:
	int delay;
	void processBuffer(FormatData&, unsigned char* buffer, int bufferSize);
	Echo(int delay);
	Echo();
	int getDelay();
	virtual ~Echo();
	void setDelay(int newDelay);
};
#endif //ECHO_H
