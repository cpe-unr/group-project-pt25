#include <string>
#include <iostream>
#include "Echo.h"
#include "Wav.h"
#include "Processor.h"
Echo::Echo() {
}
Echo::Echo(int newDelay){
	Echo::setDelay(newDelay);
}
Echo::~Echo() {
	
}
void Echo::processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){ //Echo processor for 16 bit stereo
	for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
		if((bufferLeft[bufferIndex]) > 14090){
		}
		else{
			bufferLeft[i] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-delay];
		}
	}

	for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
		if((bufferRight[i]) > 14090){
		}
		else{
			bufferRight[i] = bufferRight[i] + bufferRight[i-delay];
		}
	}
}
void Echo::processBuffer16Bitmono(unsigned char* buffer, int bufferSize){ //Echo processor for 16 bit mono
	for (int i = 0; i <= bufferSize; i++){
		if((buffer[i]) > 14090){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
	}
}
void Echo::process8BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){ //Echo processor for 8 Bit stereo

	for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
		if((bufferLeft[bufferIndex]) > 110){
		}
		else{
			bufferLeft[i] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-delay];
		}
	}

	for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
		if((bufferRight[i]) > 110){
		}
		else{
			bufferRight[i] = bufferRight[i] + bufferRight[i-delay];
		}
	}
}
void Echo::processBuffer8bitMono(unsigned char* buffer, int bufferSize){ //Echo processor for 8 bit mono
	for(int i = 0; i < bufferSize-1; i++){
		if((buffer[i]) > 110){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-delay];
		}
	}
}
void Echo::setDelay(int newDelay){
	delay = newDelay;
}
