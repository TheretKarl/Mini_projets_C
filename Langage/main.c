#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include <time.h>

int main(int argc, char argv[]){
  char *str = "Je suis une chaine qui { suit un pattern }}}} !";
  printf("[%d]\n", find_pattern('{', '}', str));
  check_file("langage.txt");
  return 0;
}
