/*
#include"Echo.h"
#include"Processor.h"
#include <string>
#include <fstream>
#include <iostream>
#include "Noisegate.h"
NoiseGate::NoiseGate(){
	amplitude = 0;
}

NoiseGate::NoiseGate(double nAmplitude){
	NoiseGate::setAmpitude(nAmplitude);
}
void NoiseGate::processMono8Bit(int size, unsigned char* buffer){

	for(int i = 0; i < size-1; i++){
		if(buffer[i]*amplitude < 129*amplitude){
			 buffer[i] = 128;
		}
	
	}
}

void NoiseGate::processStereo8Bit(int sizeLeft, int sizeRight, unsigned char* bufferLeft, unsigned char* bufferRight){
	
	for(int i = 0; i < sizeLeft-1; i++){
		if(bufferLeft[i]*amplitude < 129*amplitude){
			 bufferLeft[i] = 128;
		}
	}

	for(int i = 0; i < sizeRight-1; i++){
		if(bufferRight[i]*amplitude < 129*amplitude){
			 bufferRight[i] = 128;
		}

	}
}

void NoiseGate::processMono16Bit(int size, short* buffer){

	for(int i = 0; i < size-1; i++){
		if(buffer[i]*amplitude < 16385*amplitude){
			 buffer[i] = 0;
		}
	}
}

void NoiseGate::processStereo16Bit(int sizeLeft, int sizeRight, short* bufferLeft, short* bufferRight){
	
	for(int i = 0; i < sizeLeft-1; i++){
		if(bufferLeft[i]*amplitude < 16385*amplitude){
			 bufferLeft[i] = 0;
		}
	}

	for(int i = 0; i < sizeRight-1; i++){
		if(bufferRight[i]*amplitude < 16385*amplitude){
			 bufferRightbufferRight[i] = 0;
		}
	}
}
double NoiseGate::getAmp(){
	return amplitude;
}
void NoiseGate::setAmp(double nAmplitude){
	amplitude = nAmplitude;
}
*/