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
void Echo::processBuffer16BitStereo(unsigned char* buffer, int bufferSize){ //Echo processor for 16 bit stereo
	int i;
	int pain = Echo::delay;
	for (i = pain; i <= bufferSize; i++){
		buffer[i] = (buffer[i] + buffer[i - pain])/2;
	}
}
void Echo::processBuffer16Bitmono(unsigned char* buffer, int bufferSize){ //Echo processor for 16 bit mono
	int i;
	int pain = Echo::delay;
	for (i = pain; i <= bufferSize; i++){
		buffer[i] = (buffer[i] + buffer[i - pain])/2;
	}
}
void Echo::processBuffer8BitStereo(unsigned char* buffer, int bufferSize){ //Echo processor for 8 bit stereo
	int i;
	int pain = Echo::delay;
	for (i = pain; i <= bufferSize; i++){
		buffer[i] = (buffer[i] + buffer[i - pain])/2;
	}
}
void Echo::processBuffer8bitMono(unsigned char* buffer, int bufferSize){ //Echo processor for 8 bit mono
	int i;
	int pain = Echo::delay;
	for (i = pain; i <= bufferSize; i++){
		buffer[i] = (buffer[i] + buffer[i - pain])/2;
	}
}
void Echo::setDelay(int newDelay){
	delay = newDelay;
}
