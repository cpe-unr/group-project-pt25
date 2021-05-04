#ifndef NOISEGATE_H
#define NOISEGATE_H
#include"Processor.h"

class NoiseGate : public Processor
{
public:
	NoiseGate();
	NoiseGate::NoiseGate(double nAmplitude);
	void processBuffer(FormatData&, unsigned char* buffer, int bufferSize);
	double NoiseGate::getAmp();
	void NoiseGate::setAmp(double nAmplitude);
	virtual ~NoiseGate();
private:
	double amplitude;
};

#endif //NOISEGATE_H
