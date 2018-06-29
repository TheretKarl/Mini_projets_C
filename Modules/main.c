#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(int argc, char *argv[]){
  list_char *first = allocation_list_char('A');
  list_char *add1 = allocation_list_char('B');
  list_char *add2 = allocation_list_char('C');
  list_char *liste = NULL;
  add_list_char(&liste, first);
  add_list_char(&liste, add1);
  add_list_char(&liste, add2);
  print_list_char(liste);
  pop_list_char(&liste);
  print_list_char(liste);
  free_list_char(liste);
  return 0;
}
