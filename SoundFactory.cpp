#include <exception>
#include <fstream>
#include "SoundFactory.h"
#include "WavHeader.h"
#include "EightBitMono.h"
#include "EightBitStereo.h"
#include "SixteenBitMono.h"
#include "SixteenBitStereo.h"

wav_header readHeader(const std::string &fileName)
{
	wav_header waveHeader;
    std::ifstream file(fileName,std::ios::binary | std::ios::in);
    if(file.is_open())
	{
        file.read((char*)&waveHeader, sizeof(wav_header));
        file.close();
    }
	return waveHeader;
}

std::unique_ptr <SoundInterface> makeSound(const std::string &fileName)
{
	std::unique_ptr <SoundInterface> interface;
	auto waveHeader = readHeader(fileName);
	if(waveHeader.bit_depth == 8)
	{
		if(waveHeader.num_channels == 1)
		{
			interface.reset (new EightBitMono);
		}
		else if(waveHeader.num_channels == 2)
		{
			interface.reset (new EightBitStereo);
		}
	}
	else if(waveHeader.bit_depth == 16)
	{
		if(waveHeader.num_channels == 1)
		{
			interface.reset (new SixteenBitMono);
		}
		else if(waveHeader.num_channels == 2)
		{
			interface.reset (new SixteenBitStereo);
		}
	}
	else
	{
		throw std::runtime_error("Unsupported File Type");
	}
	return interface;
}