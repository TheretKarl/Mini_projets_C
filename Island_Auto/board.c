#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include "prototypes_island.h"
#include <string.h>

square *allocate_square(int id){
  square *s = (square *)(malloc(sizeof(square)));
  if(s == NULL){
    printf("Error during allocation !\n");
    return NULL;
  }

  s->id = id;
  s->type_land = NULL;
  s->type_sea  = NULL;

  return s;
}

void change_square_type(square **s, land *type_l, sea *type_s){
  if(type_l != NULL){
    if((*s)->type_sea == NULL){
      (*s)->type_land = type_l;
    }
  }
  else if(type_s != NULL){
    if((*s)->type_land == NULL){
      (*s)->type_sea = type_s;
    }
  }
}

void print_square(square *s){
  printf("%d ", s->id);
}

void free_square(square *s){
  free(s);
}


board *allocate_board(int size){
  board *b = (board *)(malloc(sizeof(square)));
  if(b == NULL){
    printf("Error during allocation !\n");
    return NULL;
  }

  b->size = size;

  b->unit = (square ***)(malloc(sizeof(square **) * (size)));
  if(b->unit == NULL){
    printf("Error during allocation !\n");
    return NULL;
  }
  
  int i, j;
  int n = 0;
  for(i = 0; i < size; i++){
    b->unit[i] = (square **)(malloc(sizeof(square *) * (size)));
    if(b->unit[i] == NULL){
      printf("Error during allocation !\n");
      return NULL;
    }
    for(j = 0; j < size; j++){
      b->unit[i][j] = allocate_square(n);
      n++;
    }
  }

  return b;
}

void print_board(board *b){
  int i, j;
  for(j = 0; j < b->size; j++){
    for(i = 0; i < b->size; i++){
      print_square(b->unit[j][i]);
    }
    printf("\n");
  }
}

void free_board(board *b){
  int i, j;
  for(i = 0; i < b->size; i++){
    for(j = 0; j < b->size; j++){
      free_square(b->unit[i][j]);
    }
    free(b->unit[i]);
  }
  free(b->unit);
  free(b);
}
