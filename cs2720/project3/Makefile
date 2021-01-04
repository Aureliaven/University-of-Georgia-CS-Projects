CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: bank

bank: PriorityQueue.o QueType.o BankSimulation.o
	g++ $(CFLAGS) -o bank PriorityQueue.o QueType.o BankSimulation.o

PriorityQueue.o: PriorityQueue.cpp
	g++ $(CFLAGS) -c PriorityQueue.cpp

QueType.o: QueType.cpp
	g++ $(CFLAGS) -c QueType.cpp

BankSimulation.o: BankSimulation.cpp
	g++ $(CFLAGS) -c BankSimulation.cpp

run:
	./bank

clean:
	rm -f bank
	rm -f PriorityQueue.o QueType.o BankSimulation.o
