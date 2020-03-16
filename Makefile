all: rank

rank: list.o matrix.o main.o
	gcc -o rank list.o matrix.o main.o
 
matrix.o: matrix.c list.h
	gcc -o matrix.o -c matrix.c -Wall -O

list.o: list.c
	gcc -o list.o -c list.c -Wall -O

main.o: main.c matrix.h
	gcc -o main.o -c main.c -Wall -O

clean:
	rm -f *.o rank