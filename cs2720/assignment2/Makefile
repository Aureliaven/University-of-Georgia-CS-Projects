CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: queue

queue: PriorityQueue.o PriorityQueueDr.o
	g++ $(CFLAGS) -o queue PriorityQueue.o PriorityQueueDr.o

PriorityQueue.o: PriorityQueue.cpp
	g++ $(CFLAGS) -c PriorityQueue.cpp

PriorityQueueDr.o: PriorityQueueDr.cpp
	g++ $(CFLAGS) -c PriorityQueueDr.cpp

run:
	./queue

clean:
	rm -f queue
	rm -f PriorityQueue.o PriorityQueueDr.o
