CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: tree

tree: TreeType.o QueType.o TreeDr.o
	g++ $(CFLAGS) -o tree TreeType.o QueType.o TreeDr.o

TreeType.o: TreeType.cpp
	g++ $(CFLAGS) -c TreeType.cpp

QueType.o: QueType.cpp
	g++ $(CFLAGS) -c QueType.cpp

TreeDr.o: TreeDr.cpp
	g++ $(CFLAGS) -c TreeDr.cpp

run:
	./tree

clean:
	rm -f tree
	rm -f TreeType.o QueType.o TreeDr.o
