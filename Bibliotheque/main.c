#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"
#include <time.h>

int main(int argc, char argv[]){
  char *chaine1 = create_name("Chaine Etrange ... ");
  char *chaine2 = create_name("En effet !");
  char *chaine3 = create_str_add(chaine1, chaine2, '\n');
  printf("%s %s\n", chaine1, chaine2);
  printf("%s\n", chaine3);
  free(chaine3);
  free(chaine2);
  free(chaine1);
  
  
  return 0;
}
