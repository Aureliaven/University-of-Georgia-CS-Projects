CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -std=c++14 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile: lab07.out

lab07.out: lab07.cpp
	$(CC) $(CFLAGS) -o lab07.out lab07.cpp

run: lab07.out
	./lab07.out

clean:
	rm lab07.out

