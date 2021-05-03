/*
#ifndef NOISEGATE_H
#define NOISEGATE_H
#include"Processor.h"

class NoiseGate : public Processor
{
public:
	NoiseGate();
	void NoiseGate::processMono8Bit(int size, unsigned char* buffer);
	NoiseGate::NoiseGate(double nAmplitude);
	void NoiseGate::processStereo8Bit(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight);
	void NoiseGate::processMono8Bit(int size, unsigned char* buffer);
	void NoiseGate::processMono16Bit(int size, short* buffer);
	void NoiseGate::processStereo16Bit(int sizeLeft, int sizeRight, short* bufferLeft, short* bufferRight);
	double NoiseGate::getAmp();
	void NoiseGate::setAmp(double nAmplitude);
	virtual ~NoiseGate();
private:
	double amplitude;
};

#endif //NOISEGATE_H
*/