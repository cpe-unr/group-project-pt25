#pragma once

#include "SoundInterface.h"

class SixteenBitMono : public SoundInterface
{
	public:
		~SixteenBitMono() override;
		void print() override;
};