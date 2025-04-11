main.exe: main.o 
	g++ -std=c++17 -o main.exe main.o
main.o: main.cpp matrix.hpp
	g++ -std=c++17 -c main.cpp
clean: 
	rm -f main.exe main.o