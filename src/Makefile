CC = g++

build: main.o
	$(CC) main.o -o main

main.o: main.cpp
	$(CC) -c main.cpp

run: main
	./main $(path)

clean:
	rm *.o output

