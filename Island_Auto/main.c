#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include "prototypes_island.h"
#include <string.h>

int main(int argc, char *argv[]){
  board *b = allocate_board(10);
  print_board(b);
  free_board(b);

  str_int *s1 = allocate_str_int("bois", 10);
  str_int *s2 = allocate_str_int("pierre", 89);
  list_str_int *l = NULL;
  add_list_str_int(&l, s1);
  add_list_str_int(&l, s2);
  
  return 0;
}
