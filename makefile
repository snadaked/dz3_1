
all: main

main: main.o parser.o solver.o
	g++ main.o parser.o solver.o -o main

main.o: main.cpp
	g++ -c main.cpp

parser.o: parser.cpp
	g++ -c parser.cpp

solver.o: solver.cpp
	g++ -c solver.cpp

clean:
	rm -f *.o main
