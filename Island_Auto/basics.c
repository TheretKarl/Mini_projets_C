#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include <string.h>

int length_str(char *str){
  int i = 0;
  while(str[i]){
    i++;
  }

  return i;
}

char *create_str(char *str){
  int i = length_str(str);
  int n = 0;
  char *s = malloc(sizeof(char) * (i + 1));
  for(n = 0; n < i; n++){
    s[n] = str[n];
  }
  s[n] = '\0';

  return s;
}

int max(int a, int b){
  if(a >= b){
    return a;
  }
  else {
    return b;
  }
}

int min(int a, int b){
  if(a < b){
    return a;
  }
  else {
    return b;
  }
}

int gap_between(int a, int b){
  int nb_max = max(a,b);
  int nb_min = min(a,b);
  printf("[%d,%d]\n", nb_max, nb_min);

  if(nb_max >= 0 && nb_min >= 0){
    return nb_max - nb_min;
  }
  else if(nb_min < 0 && nb_max >= 0){
    return nb_max - nb_min;
  }
  else if(nb_min < 0 && nb_max < 0){
    return -nb_max + nb_min;
  }
  return 0; // Is not supposed to happen
}

str_int *allocate_str_int(char *str, int data){
  str_int *si = (str_int *)(malloc(sizeof(str_int)));
  if(si == NULL){
    printf("Error during allocation !\n");
    return NULL;
  }

  si->str = create_str(str);
  si->data = data;

  return si;
}

void print_str_int(str_int *si){
  printf("%s %d", si->str, si->data);
}

void free_str_int(str_int *si){
  free(si->str);
  free(si);
}
