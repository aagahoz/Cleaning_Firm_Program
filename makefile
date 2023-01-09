all: clean compile link run

clean:
	rm -rf *.o ; rm -rf main ; rm -rf ./lib/*.o ; rm -rf ./bin/main

compile:
	g++ -I ./include/ -o ./lib/library.o -c ./library.cpp
	g++ -o ./lib/main.o -c main.cpp

link:
	g++ -I ./include/ -o ./bin/main ./lib/library.o ./main.cpp

run:
	rm -rf *.o
	./bin/main