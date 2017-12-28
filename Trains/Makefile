# A faire !

CFLAGS=-g 
CC=gcc

all:main

trains.o: structures.h prototypes.h trains.c
	$(CC) -c $(CFLAGS) trains.c
	
main.o: structures.h prototypes.h main.c
	$(CC) -c $(CFLAGS) main.c
	
main:trains.o main.o structures.h prototypes.h
	$(CC) -o main $(CFLAGS) trains.o main.o

clean: 
	rm -f *.o main
