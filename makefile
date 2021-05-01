audioprocessor: main.cpp Wav.o Echo.o Noisegate.o CSV.o Normalization.o
	g++ -o audioprocessor Wav.o Echo.o Noisegate.o CSV.o Normalization.o main.cpp
Wav.o: Wav.cpp Wav.h
	g++ -c -std=c++11 Wav.cpp
Echo.o: Echo.cpp Echo.h
	g++ -c -std=c++11 Echo.cpp
Noisegate.o: Noisegate.cpp Noisegate.h
	g++ -c -std=c++11 Noisegate.cpp
CSV.o: CSV.cpp CSV.h
	g++ -c -std=c++11 CSV.cpp
Normalization.o: Normalization.cpp Normalization.h
	g++ -c -std=c++11 Normalization.cpp
clean:
	rm *.o audioprocessor
