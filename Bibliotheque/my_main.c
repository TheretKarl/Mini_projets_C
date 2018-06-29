#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

int main(int argc, char *argv[]){
  printf("%d\n", check_int("123"));
  printf("%d\n", check_int("12&&"));
  printf("%d\n", check_int("Pas un nombre"));
  printf("%d\n", check_int("123456789123456789"));
  printf("2^4 = %d\n", pow_n(2,4));
  int a,b;
  strint("123", &a);
  strint("-123", &b);
  printf("%d %d\n", a,b);
  return 0;
}
