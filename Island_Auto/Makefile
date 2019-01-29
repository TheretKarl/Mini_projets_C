CC = gcc
SRC = board.c land.c sea.c
OBJ = $(SRC:.c=.o)


all : main

main : main.o $(OBJ) librarys.a
	$(CC) -o $@ $^

%.o:%.c
	$(CC) -o $@ -c $<

clean :
	rm -rf *.o
	rm -rf main
	rm -fv *~
.PHONY : all clean


