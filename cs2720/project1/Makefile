CFLAGS = -Wall -std=c++14 -g -O0 -pedantic-errors
compile: ulist

ulist: UnsortedList.o UnsortedListDriver.o Student.o
	g++ $(CFLAGS) -o ulist UnsortedList.o UnsortedListDriver.o Student.o

UnsortedList.o: UnsortedList.cpp
	g++ $(CFLAGS) -c UnsortedList.cpp

UnsortedListDriver.o: UnsortedListDriver.cpp
	g++ $(CFLAGS) -c UnsortedListDriver.cpp

Student.o: Student.cpp
	g++ $(CFLAGS) -c Student.cpp

run:
	./ulist

clean:
	rm -f ulist
	rm -f UnsortedList.o UnsortedListDriver.o Student.o
