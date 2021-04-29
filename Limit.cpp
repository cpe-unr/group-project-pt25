#include <string>
#include <iostream>
#include "Limiter.h"
#include "Wav.h"
#include "Processor.h"
Limiter::Limiter(){
}
Limiter::~Limiter(){
	
}
void Limiter::processBuffer(unsigned char* buffer, int bufferSize){
	for(int i = 0; i < bufferSize; i++) {
		if(buffer[i] > 230 || buffer[i] < 25) {
			if(buffer[i] > 230){
				buffer[i] = 230;
			}
			else {
				buffer[i] = 25;
			}
		}
		
	}
}
