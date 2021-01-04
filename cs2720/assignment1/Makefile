CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: queue

queue: QueType.o QueDr.o
	g++ $(CFLAGS) -o queue QueType.o QueDr.o

QueType.o: QueType.cpp
	g++ $(CFLAGS) -c QueType.cpp

QueDr.o: QueDr.cpp
	g++ $(CFLAGS) -c QueDr.cpp

run:
	./queue

clean:
	rm -f queue
	rm -f QueType.o QueDr.o
