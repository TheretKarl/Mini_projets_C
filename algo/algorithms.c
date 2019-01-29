#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include <string.h>


void find_pos_x(int x, int y, point *p, list_str *path, info_pos *pos){
  add_list_str(&path, p->str);
  check_info_pos(x, y, &pos);
  if(p->north && is_not_in_list_str(path, p->north->str)){
    y++;
    find_pos_x(x, y, p->north, path, pos);
  }
  if(p->east && is_not_in_list_str(path, p->east->str)){
    x++;
    find_pos_x(x, y, p->east, path, pos);
  }
  if(p->south && is_not_in_list_str(path, p->south->str)){
    y--;
    find_pos_x(x, y, p->south, path, pos);
  }
  if(p->west && is_not_in_list_str(path, p->west->str)){
    x--;
    find_pos_x(x, y, p->west, path, pos);
  }
  pop_list_str(&path);
}

char **initialize_matrix_str_value(int x, int y){
  /* x is the number of str per line and y the number of line */
  //printf("[%d,%d] --> %d cases\n", x, y, (x+1) * (y+1));
  char **tab = (char **)(malloc(sizeof(char *) * ((x + 1) * (y + 1))));
  int nx;
  int ny;
  for(ny = 0; ny <= y; ny++){
    for(nx = 0; nx <= x; nx++){
      //printf("Mis à NULL : %d\n", nx + ny *(x + 1));
      tab[nx + ny *(x + 1)] = NULL;
      //printf("Ligne: %d, index de ligne : %d\n",ny, nx);
    }
  }

  //tab[10] = create_str("CHAI");
			   
  return tab;
}

matrix_str *allocate_matrix_str(int x, int y){
  matrix_str *m = malloc(sizeof(matrix_str));
  if(m == NULL){
    printf("Error during allocation\n");
    return NULL;
  }

  m->tab = initialize_matrix_str_value(x, y);
  m->x = x;
  m->y = y;

  return m;
}

// access to an element in matrix -> x + y *(m->x + 1)

char *get_element_matrix_str(matrix_str *m, int x, int y){
  //printf("(%d,%d) --> %d\n", x, y, x + y * (m->x + 1));
  if(x > m->x || y > m->y){
    //printf("element NULL\n");
    return NULL;
  }
  
  return m->tab[x + y *(m->x + 1)];
  //return NULL;
}

void print_matrix_str(matrix_str *m){
  printf("width=%d, height=%d\n", m->x, m->y);
  int nx;
  int ny;
  char *tmp = NULL;
  for(ny = 0; ny <= m->y; ny++){
    for(nx = 0; nx <= m->x; nx++){
      //printf("Postion act : %d\n", nx + ny * m->y);
      tmp = get_element_matrix_str(m, nx, ny);
      if(tmp == NULL){
	printf("NULL ");
      }
      else {
	printf("%s ", tmp);
      }
    }
    printf("\n");
  }
}

// access to an element in matrix -> x + y *(m->x + 1)

void modify_map(int x, int y, point *p, list_str *path, matrix_str **map){
  add_list_str(&path, p->str);
  print_list_str(path);
  printf("%s : (%d,%d)\n", p->str, x, y);
  (*map)->tab[x + y *((*map)->x + 1)] = create_str(p->str);
  if(p->north && is_not_in_list_str(path, p->north->str)){
    //y--;
    modify_map(x, y - 1, p->north, path, map);
  }
  if(p->east && is_not_in_list_str(path, p->east->str)){
    //x++;
    modify_map(x + 1, y, p->east, path, map);
  }
  if(p->south && is_not_in_list_str(path, p->south->str)){
    //y++;
    modify_map(x, y + 1, p->south, path, map);
  }
  if(p->west && is_not_in_list_str(path, p->west->str)){
    //x--;
    modify_map(x - 1, y, p->west, path, map);
  }
  pop_list_str(&path);
}


// Comment identifier la postion du point ?
matrix_str *create_map(point *initial){
  info_pos *ip = allocate_info_pos();
  list_str *l = NULL;

  find_pos_x(0,0,initial, l, ip);
  print_info_pos(ip);
  int gap_x = gap_between(ip->min_x, ip->max_x);
  int gap_y = gap_between(ip->min_y, ip->max_y);
  int x = -(ip->min_x);
  int y =  (ip->max_y);
  printf("Position du témon : (%d,%d)\n", x, y);

  l = NULL;
  matrix_str *m = allocate_matrix_str(gap_x, gap_y);
  print_matrix_str(m);
  modify_map(x, y, initial, l, &m);
  print_matrix_str(m);
  return m;
}
