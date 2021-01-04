CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: p3

p3: p3.o Matrix.o
	g++ $(CFLAGS) -o p3 p3.o Matrix.o

p3.o: p3.cpp Matrix.h
	g++ $(CFLAGS) -c p3.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ $(CFLAGS) -c Matrix.cpp

run:
	./p3

clean:
	rm -f p3
	rm -f p3.o Matrix.o
