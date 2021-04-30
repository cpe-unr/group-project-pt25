audioprocessor: main.cpp Wav.o Limiter.o Echo.o NoiseGate.o
	g++ -std=c++11 main.cpp Wav.o Limiter.o Echo.o NoiseGate.o -o audioprocessor

Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp

lim.o: Limiter.cpp Limiter.h
	g++ -c -std=c++11 Limiter.cpp
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
NoiseGate.o: NoiseGate.cpp NoiseGate.h
	g++ -c -std=c++11 NoiseGate.cpp
clean:
	rm *.o audioprocessor
