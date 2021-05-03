#pragma once

#include "SoundInterface.h"

class EightBitStereo : public SoundInterface
{
	public:
		~EightBitStereo() override;
		void print() override;
};