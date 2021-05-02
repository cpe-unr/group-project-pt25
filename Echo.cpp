#include <string>
#include <iostream>
#include "Echo.h"
#include "Wav.h"
#include "Processor.h"

using namespace std;

Echo::Echo() {
}
Echo::Echo(int newDelay){
	Echo::setDelay(newDelay);
}
Echo::~Echo() {
	
}
void Echo::processBuffer16BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){ //Echo processor for 16 bit stereo
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
void Echo::processBuffer16Bitmono(unsigned char* buffer, int bufferSize){ //Echo processor for 16 bit mono
	int cDelay = delay;
	for (int i = 0; i <= bufferSize; i++){
		if((buffer[i]) > 14090){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-cDelay];
		}
	}
}
void Echo::process8BitStereo(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){ //Echo processor for 8 Bit stereo
	int cDelay = delay;
	for(int bufferIndex = 0; bufferIndex < sizeLeft-1; bufferIndex++){
		if((bufferLeft[bufferIndex]) > 110){
		}
		else{
			bufferLeft[bufferIndex] = bufferLeft[bufferIndex] + bufferLeft[bufferIndex-cDelay];
		}
	}

	for(int bufferIndex = 0; bufferIndex < sizeRight-1; bufferIndex++){
		if((bufferRight[bufferIndex]) > 110){
		}
		else{
			bufferRight[bufferIndex] = bufferRight[bufferIndex] + bufferRight[bufferIndex-cDelay];
		}
	}
}
void Echo::processBuffer8bitMono(unsigned char* buffer, int bufferSize){ //Echo processor for 8 bit mono
	int cDelay = delay;
	for(int i = 0; i < bufferSize-1; i++){
		if((buffer[i]) > 110){
		}
		else{
			buffer[i] = buffer[i] + buffer[i-cDelay];
		}
	}
}
void Echo::setDelay(int newDelay){
	delay = newDelay;
}
int Echo::getDelay(){
	return delay;
}
