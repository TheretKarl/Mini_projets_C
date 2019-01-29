#ifndef prototypes
#define prototypes

// bases.c
int length_str(char *str);
char *create_str(char *str);
int file_line(char *file_name);
char **array_str_file(char *file_name);
void print_array_str(char **array_str);
void free_array_str(char **array_str);
char *add_str(char *str1, char *str2, char add);
char *add_str_array(char **array_str, char add);
int max(int a, int b);
int min(int a, int b);
int gap_between(int a, int b);

// list_bases.c
typedef struct _list_str{
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

// str_int.c

typedef struct _str_int {
  int data;
  char *str;
} str_int;

str_int *allocate_str_int(char *str, int data);
void print_str_int(str_int *si);
void free_str_int(str_int *si);

typedef struct _list_str_int {
  str_int *data;
  struct _list_str_int *next;
} list_str_int;

list_str_int *allocate_list_str_int(str_int *data);
void add_list_str_int(list_str_int **list, str_int *data);
str_int *pop_list_str_int(list_str_int **list);

#endif


