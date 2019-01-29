#ifndef prototypes
#define prototypes

// basics.c
int length_str(char *str);
char *create_str(char *str);
int max(int a, int b);
int min(int a, int b);
int gap_between(int a, int b);

// list.c
typedef struct _list_str {
  char *str;
  struct _list_str *next;
} list_str;

list_str *allocate_list_str(char *str);
void add_list_str(list_str **list, char *str);
char *pop_list_str(list_str **list);
int is_not_in_list_str(list_str *list, char *str);
void print_list_str(list_str *list);

int length_list_str(list_str *list);
char **allocate_tab_str_from_list(list_str *list);
void print_tab_str(char **tab);

// points.c

typedef struct _point {
  char *str;
  struct _point *north;
  struct _point *east;
  struct _point *south;
  struct _point *west;
} point;

point *allocate_point(char *str);
void add_direction(char c, point **origin, point **dest);

typedef struct _info_pos {
  int min_x;
  int max_x;
  int min_y;
  int max_y;
} info_pos;

info_pos *allocate_info_pos();
void check_info_pos(int x, int y, info_pos **p);
void print_info_pos(info_pos *p);

// algorithms.c

void find_pos_x(int x, int y, point *p, list_str *path, info_pos *pos);

typedef struct _matrix_str {
  int x;
  int y;
  char **tab;
} matrix_str;

char **initialize_matrix_str_value(int x, int y);
matrix_str *allocate_matrix_str(int x, int y);
char *get_element_matrix_str(matrix_str *m, int x, int y);
void print_matrix_str(matrix_str *m);

void modify_map(int x, int y, point *p, list_str *path, matrix_str **map);
matrix_str *create_map(point *initial);

#endif
