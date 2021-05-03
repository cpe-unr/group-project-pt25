#include <iostream>
#include "SixteenBitStereo.h"

using namespace std;
SixteenBitStereo::~SixteenBitStereo()
{}

void SixteenBitStereo::print()
{
	std::cout << "16-Bit Stereo\n";
}
void SixteenBitStereo::processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){ //Echo processor for 16 bit stereo
	int cDelay = delay;
	for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
		if((bufferLeft[bufferIndex]) > 14090){
		}
		else{
			bufferLeft[bufferIndex] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-cDelay];
		}
	}
	for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
		if((bufferRight[bufferIndex]) > 14090){
		}
		else{
			bufferRight[bufferIndex] = bufferRight[bufferIndex] + bufferRight[bufferIndex-cDelay];
		}
	}
}
void SixteenBitStereo::processStereo16Bit(int sizeLeft, int sizeRight, short* bufferLeft, short* bufferRight){ //Noise gate
	for(int i = 0; i < sizeLeft-1; i++){
		if(bufferLeft[i]*amplitude < 16385*amplitude){
			 bufferLeft[i] = 0;
		}
	}

	for(int i = 0; i < sizeRight-1; i++){
		if(bufferRight[i]*amplitude < 16385*amplitude){
			 bufferRight[i] = 0;
		}
	}
}
