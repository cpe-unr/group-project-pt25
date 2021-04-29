#ifndef NOISEGATE_H
#define NOISEGATE_H
#include"Processor.h"

class NoiseGate : public Processor
{
public:
	int index = 0;
	void processBuffer(unsigned char* buffer, int bufferSize);
	NoiseGate();
	virtual ~NoiseGate();
};

#endif //NOISEGATE_H
© 2021 GitHub, Inc.
