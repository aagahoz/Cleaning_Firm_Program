all: clean compile link run

clean:
	rm -rf *.o ; rm -rf main

compile:
	g++ -o main.o -c main.cpp

link:
	g++ -o main main.o

run:
	./main