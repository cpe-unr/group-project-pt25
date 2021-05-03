audioprocessor: main.cpp EightBitMono.o EightBitStereo.o SixteenBitMono.o SixteenBitStereo.o SoundFactory.o Echo.o Noisegate.o Normalization.o
	g++ -o audioprocessor EightBitMono.o EightBitStereo.o SixteenBitMono.o SixteenBitStereo.o SoundFactory.o Echo.o Noisegate.o Normalization.o main.cpp
EightBitMono.o:	EightBitMono.cpp EightBitMono.h
	g++ -c -std=c++11 EightBitMono.cpp
EightBitStereo.o:	EightBitStereo.cpp EightBitStereo.h
	g++ -c -std=c++11 EightBitStereo.cpp
SixteenBitMono.o:	SixteenBitMono.cpp SixteenBitMono.h
	g++ -c -std=c++11 SixteenBitMono.cpp
SixteenBitStereo.o:	SixteenBitStereo.cpp SixteenBitStereo.h
	g++ -c -std=c++11 SixteenBitStereo.cpp
SoundFactory.o: SoundFactory.cpp SoundFactory.h
	g++ -c -std=c++11 SoundFactory.cpp
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
Noisegate.o: Noisegate.cpp Noisegate.h
	g++ -c -std=c++11 Noisegate.cpp
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp
clean:
	rm *.o audioprocessor