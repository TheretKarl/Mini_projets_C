CC = gcc
CFLAGS = -g
AR = ar
ARFLAGS = cr
LIB_SRC = fonctions_base.c fonctions_list.c fonctions_maths.c
LIB_OBJ = $(LIB_SRC:.c=.o)
RANLIB = ranlib


all: libperso.a main_test

%.o : %.c
	$(CC) -c $< -o $@

libperso.a: prototypes.h $(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $(LIB_OBJ)
	$(RANLIB) $@

main_test: my_main.o libperso.a 
	$(CC) -o $@ $(CFLAGS) $^

clean :
	rm -f *.o
	rm -f main_test libperso.a

.PHONY: all clean

