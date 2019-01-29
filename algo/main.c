#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"
#include <string.h>

int main(int argc, char *argv[]){

  point *p1 = allocate_point("P1");
  point *p2 = allocate_point("P2");
  point *p3 = allocate_point("P3");
  point *p4 = allocate_point("P4");
  point *p5 = allocate_point("P5");
  point *p6 = allocate_point("P6");
  point *p7 = allocate_point("P7");

  add_direction('N', &p1, &p2);
  add_direction('N', &p2, &p3);
  add_direction('N', &p3, &p4);
  add_direction('N', &p4, &p5);
  add_direction('E', &p5, &p6);
  add_direction('W', &p1, &p7);

  info_pos *p = allocate_info_pos();
  list_str *l = NULL;
  print_info_pos(p);
  find_pos_x(0,0,p1, l, p);
  print_info_pos(p);

  printf("Ecart : (%d, %d)\n", gap_between(p->min_x, p->max_x), gap_between(p->min_y, p->max_y));
  matrix_str *m = allocate_matrix_str(gap_between(p->min_x, p->max_x),  gap_between(p->min_y, p->max_y));
  print_matrix_str(m);

  printf("Map 2 :\n");
  matrix_str *m2 = create_map(p1);
  //print_matrix_str(m2);
    
    /*
  add_list_str(&l, "a");
  add_list_str(&l, "b");
  add_list_str(&l, "c");
  add_list_str(&l, "d");

  
  char **tab = allocate_tab_str_from_list(l);
  print_tab_str(tab);
    */
  return 0;
}
