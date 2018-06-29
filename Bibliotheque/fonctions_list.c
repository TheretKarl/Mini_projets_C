#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

list_str *allocate_list_str(char *str){
  /* Allocate a portion of list of string
   *next is set as NULL */
  list_str *list = (list_str *)(malloc(sizeof(list)));
  if(list == NULL){
    printf("Erreur lors de l'allocation\n");
    exit(0);
  }

  list->str = create_str(str);
  list->next = NULL;

  return list;
}

list_str *add_list_str(list_str *list, char *str){
  /* Create a new list of string if first parameter is NULL
     otherwize set the first parameter as the list of string 
     you want to add a string(second parameter) */
  list_str *add_str = allocate_list_str(str);
  if(list == NULL){
    list = add_str;
    return list;
  }
  add_str->next = list;
  return add_str;
}

void free_list_str(list_str *list){
  /* Free the entiry list and the string with it */
  list_str *cpy;
  while(list){
    cpy = list;
    list = list->next;
    free(cpy->str);
    free(cpy);
  }
}

void print_list_str(list_str *list){
  /* print out the entirely list, with \n */
  while(list){
    printf("%s\n", list->str);
    list = list->next;
  }
}

char *remove_list_str(list_str **list, char *str){
  /* **list is the adress of the str list
     Remove an element equal to str which is allocated
     If not found, return NULL */
  list_str *cpy = *list;
  list_str *save = *list;

  while(cpy && strcmp(cpy->next->str, str)){
    cpy = cpy->next;
  }

  if(cpy == NULL){
    return NULL;
  }

  char *str_remove = cpy->next->str;
  list_str *remove = cpy->next;
  cpy->next = remove->next;
  free(remove);
  (*list) = save;
  return str_remove;
}

char *copy_element_list_str(list_str *list, char*str){
  /* **list is the adress of the str list
     return a copy of an element equal to str which is allocated
  Return NULL if not found*/
  while(list && strcmp(list->str, str)){
    list = list->next;
  }
  
  if(list == NULL){
    return NULL;
  }
  return create_str(list->str);
}

char *pop_list_str(list_str **list){
  /* Pop out the first element of the list */
  char *str = (*list)->str;
  list_str *cpy = *list;
  (*list) = (*list)->next;
  free(cpy);
  return str;
}

int element_in_list_str(list_str *list, char *element){
  /* Return 1 if the element is in the list, 0 else */
  while(list){
    if(!strcmp(list->str, element)){
      return 1;
    }
    list = list->next;
  }

  return 0;
}
