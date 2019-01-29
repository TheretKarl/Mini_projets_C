CC = gcc
SRC = basics.c  list.c points.c algorithms.c
OBJ = $(SRC:.c=.o)


all : main

main : main.o $(OBJ)
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $<

clean :
	rm -rf *.o
	rm -rf main
	rm -fv *~


