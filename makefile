run: main
	./main

main: main.o memorymap.o
	g++ main.o memorymap.o -o main

main.o: main.cpp
	g++ -c main.cpp

memorymap.o: memorymap.cpp memorymap.hpp
	g++ -c memorymap.cpp

clean:
	rm *.o main