CC = g++
DEBUG = -g
CFLAGS = -Wall -pedantic-errors -std=c++14 $(DEBUG)
LFLAGS = -Wall $(DEBUG)

compile:
	$(CC) $(CFLAGS) -o rectangle2 rectangle2.cpp
	$(CC) $(CFLAGS) -o student student.cpp
runstudent:
	./student
runrectangle2:
	./rectangle2

clean:
	rm rectangle2
	rm student

