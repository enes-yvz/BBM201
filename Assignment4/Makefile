Main: Main.o Decoder.o Encoder.o Node.o Sorter.o
	g++ -std=c++11 Main.o Decoder.o Encoder.o Node.o Sorter.o -o Main
	
Main.o : Main.cpp
	g++ -c -std=c++11 Main.cpp
	
Decoder.o : Decoder.cpp
	g++ -c -std=c++11 Decoder.cpp
	
Encoder.o : Encoder.cpp
	g++ -c -std=c++11 Encoder.cpp
	
Node.o : Node.cpp
	g++ -c -std=c++11 Node.cpp
	
Sorter.o : Sorter.cpp
	g++ -c -std=c++11 Sorter.cpp
	
clean: 
	rm *.o Main