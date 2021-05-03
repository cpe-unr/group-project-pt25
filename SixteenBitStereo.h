#pragma once

#include "SoundInterface.h"

class SixteenBitStereo : public SoundInterface
{
	public:
		~SixteenBitStereo() override;
		void print() override;
};