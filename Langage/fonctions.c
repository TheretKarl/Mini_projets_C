#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define MAX_FILE 300

int length_str(char *str){
  int i = 0;
  while(str[i] != '\0' && str[i] != '\n'){
    i++;
  }
  return i;
}

char *create_str(char *str){
  int length = length_str(str);
  char *new_str = (char *)(malloc(sizeof(char) * (length + 1)));
  if(new_str == NULL){
    printf("Une erreur est survenue !");
    return NULL;
  }
  int i;
  for(i = 0; i < length; i++){
    new_str[i] = str[i];
  }
  new_str[i] = '\0';
  return new_str;
}

int find_pattern(char begin, char end, char *str){
  int res = 0;
  int i = 0;
  while(str[i] != '\0'){
    if(str[i] == begin){
      res++;
    }
    else if(str[i] == end){
      res--;
    }
    i++;
  }
  return res;
}

void print_pattern_file(char begin, char end, int result){
  if(result > 0){
    printf("%d %c n'a pas été correctement fermé !\n", result,begin);
  }
  else if(result < 0){
    printf("%d %c est apparament en trop !\n", -result, end);
  }
}

int check_file(char *name_file){
  FILE *file = fopen(name_file, "r");
  if(file == NULL){
    printf("Une erreur lors de l'ouverture de %s est survenue !", name_file);
    return 1;
  }
  char store[MAX_FILE] = "";
  char *str = NULL;
  int res1 = 0; int res2 = 0; int res3 = 0;
  while(fgets(store, MAX_FILE, file)){
    str = create_str(store);
    res1 = res1 + find_pattern('{', '}', str);
    res2 = res2 + find_pattern('(', ')', str);
    res3 = res3 + find_pattern('[', ']', str);
  }
  print_pattern_file('{', '}', res1);
  print_pattern_file('(', ')', res2);
  print_pattern_file('[', ']', res3);
  fclose(file);
  return res1 + res2 + res3;
}
