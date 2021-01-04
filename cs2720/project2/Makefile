CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: list

list: SortedList.o SortedListDr.o
	g++ $(CFLAGS) -o list SortedList.o SortedListDr.o

SortedList.o: SortedList.cpp
	g++ $(CFLAGS) -c SortedList.cpp

SortedListDr.o: SortedListDr.cpp
	g++ $(CFLAGS) -c SortedListDr.cpp

run:
	./list

clean:
	rm -f list
	rm -f SortedList.o SortedListDr.o
