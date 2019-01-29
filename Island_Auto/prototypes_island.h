#ifndef prototypes_island
#define prototypes_island

/*
// basics.c
int length_str(char *str);
char *create_str(char *str);
int max(int a, int b);
int min(int a, int b);
int gap_between(int a, int b);

typedef struct _str_int {
  int data;
  char *str;
} str_int;

str_int *allocate_str_int(char *str, int data);
void print_str_int(str_int *si);
void free_str_int(str_int *si);

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

typedef struct _list_str_int {
  str_int *data;
  struct _list_str_int *next;
} list_str_int;

list_str_int *allocate_list_str_int(str_int *data);
void add_list_str_int(list_str_int **list, str_int *data);
str_int *pop_list_str_int(list_str_int **list);
*/

// land.c

typedef struct _land {
  //buildings *build;
  int fertility;
  //list_str_int *ressources;
  int trees;
  int animals;
} land;

// sea.c

typedef struct _sea {
  int fish;
  //weather *w; 
} sea;

// board.c

typedef struct _square {
  int id; // uniq (from 0 to (N * N -1)
  land *type_land; // may not be actif with type_sea actif (!= NULL)
  sea  *type_sea; // may not be actif with type_land actif (!= NULL)
} square;

square *allocate_square(int id);
void change_square_type(square **s, land *type_l, sea *type_s);
void print_square(square *s);
void free_square(square *s);

typedef struct _board {
  int size;
  square ***unit;
}board;

board *allocate_board(int size);
void print_board(board *b);
void free_board(board *b);


#endif
