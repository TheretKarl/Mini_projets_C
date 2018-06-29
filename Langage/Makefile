CFLAGS=-g
CC=gcc

all:main

fonctions.o:  prototypes.h fonctions.c
	$(CC) -c $(CFLAGS) fonctions.c

main.o: prototypes.h main.c
	$(CC) -c $(CFLAGS) main.c

main:fonctions.o main.o  prototypes.h
	$(CC) -o main $(CFLAGS) fonctions.o main.o

clean: 
	rm -f *.o main

mrproper:
	rm *.o
