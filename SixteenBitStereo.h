#pragma once

#include "SoundInterface.h"

class SixteenBitStereo : public SoundInterface
{
	public:
		int delay;
		int amplitude;
		~SixteenBitStereo() override;
		void print() override;
		void processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight); //Echo
		void processStereo16Bit(int sizeLeft, int sizeRight, short* bufferLeft, short* bufferRight); //Noise Gate
};
