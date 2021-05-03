#pragma once

#include "SoundInterface.h"

class EightBitMono : public SoundInterface
{
	public:
		~EightBitMono() override;
		void print() override;
};