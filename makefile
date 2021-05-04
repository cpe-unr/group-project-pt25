audioprocessor: main.cpp Chunk.o Wav.o Echo.o Noisegate.o Normalization.o
	g++ -o audioprocessor Chunk.o Wav.o Echo.o Noisegate.o Normalization.o main.cpp
Chunk.o: Chunk.cpp Chunk.h
	g++ -c -std=c++11 Chunk.cpp
Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
Noisegate.o: Noisegate.cpp Noisegate.h
	g++ -c -std=c++11 Noisegate.cpp
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp
clean:
	rm *.o audioprocessor