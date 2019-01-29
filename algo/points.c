#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include <string.h>


point *allocate_point(char *str){
  point *p = malloc(sizeof(point));
  p->str = create_str(str);
  p->north = NULL;
  p->east = NULL;
  p->south = NULL;
  p->east = NULL;

  return p;
}

void add_direction(char c, point **origin, point **dest){
  if(c == 'N'){
    (*origin)->north = *dest;
    (*dest)->south = *origin;
  }
  else if(c == 'E'){
    (*origin)->east = *dest;
    (*dest)->west = *origin;
  }
  else if(c == 'S'){
    (*origin)->south = *dest;
    (*dest)->north = *origin;
  }
  else if(c == 'W'){
    (*origin)->west = *dest;
    (*dest)->east = *origin;
  }
}

info_pos *allocate_info_pos(){
  info_pos *p = malloc(sizeof(info_pos));
  p->min_x = 0;
  p->max_x = 0;
  p->min_y = 0;
  p->max_y = 0;

  return p;
}

void check_info_pos(int x, int y, info_pos **p){
  if(x < (*p)->min_x){
    (*p)->min_x = x;
  }
  else if( x > (*p)->max_x){
    (*p)->max_x = x;
  }

  if(y < (*p)->min_y){
    (*p)->min_y = y;
  }
  else if(y > (*p)->max_y){
    (*p)->max_y = y;
  }
}

void print_info_pos(info_pos *p){
  printf("(%d, %d) - (%d, %d)\n", p->min_x, p->max_x, p->min_y, p->max_y);
}
