CFLAGS=-g
CC=gcc

all:main

files.o: prototypes.h files.c
	$(CC) -c $(CFLAGS) files.c
	
main.o: main.c
	$(CC) -c $(CFLAGS) main.c
	
main:files.o main.o prototypes.h
	$(CC) -o main $(CFLAGS) files.o main.o

clean: 
	rm -f *.o main
