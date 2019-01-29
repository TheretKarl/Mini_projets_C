#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include <string.h>

list_str *allocate_list_str(char *str){
  list_str *list = malloc(sizeof(list_str));
  list->str = create_str(str);
  list->next = NULL;

  return list;
}

void add_list_str(list_str **list, char *str){
  list_str *add = allocate_list_str(str);
  if(*list == NULL){
    *list = add;
  }
  else {
    list_str *cpy = *list;
    while(cpy->next){
      cpy = cpy->next;
    }

    cpy->next = add;
  }
}

char *pop_list_str(list_str **list){
  if(*list == NULL){ // empty list
    return NULL;
  }
  
  list_str *cpy = *list;
  list_str *cpy2 = NULL;
  
  while(cpy->next){
    cpy2 = cpy;
    cpy = cpy->next;
  }

  char *str = cpy->str;
  free(cpy);

  if(cpy2 == NULL){ // only one element
    *list = NULL;
  }
  else {
    cpy2->next = NULL;
  }

  return str;
}

int is_not_in_list_str(list_str *list, char *str){
  while(list){
    if(!strcmp(list->str, str)){
      return 0;
    }
    list = list->next;
  }

  return 1;
}

void print_list_str(list_str *list){
  int i = 0;
  while(list){
    printf("[%d : %s]\n", i, list->str);
    i++;
    list = list->next;
  }
}

int length_list_str(list_str *list){
  int i = 0;
  while(list){
    list = list->next;
    i++;
  }

  return i;
}

char **allocate_tab_str_from_list(list_str *list){
  int length = length_list_str(list);
  char **tab = (char **)(malloc(sizeof(char *) * (length + 1)));
  if(tab == NULL){
    printf("Error during allocation !\n");
    return NULL;
  }

  int i;
  for(i = 0; i < length; i++){
    tab[i] = create_str(list->str);
    printf("%s\n", tab[i]);
    list = list->next;
  }
  tab[i] = NULL;
  
  return tab;
}

void print_tab_str(char **tab){
  int i = 0;
  while(tab[i]){
    printf("[%d, %s]\n", i, tab[i]);
    i++;
  }
}
