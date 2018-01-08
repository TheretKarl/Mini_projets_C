CFLAGS=-g
CC=gcc

all:main

jardin.o: structures.h prototypes.h jardin.c
	$(CC) -c $(CFLAGS) jardin.c
	
main.o: structures.h prototypes.h main.c
	$(CC) -c $(CFLAGS) main.c
	
main:jardin.o main.o structures.h prototypes.h
	$(CC) -o main $(CFLAGS) jardin.o main.o

clean: 
	rm -f *.o main
	
mrproper:
	rm *.o
