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
	std::cout<<"ha your mom gay"<<std::endl;
}
void Echo::processBuffer(unsigned char* buffer, int bufferSize){
	int i;
	int pain = Echo::delay;
	for (i = pain; i <= bufferSize; i++){
		buffer[i] = (buffer[i] + buffer[i - pain])/2;
	}
}
void Echo::setDelay(int newDelay){
	delay = newDelay;
}
