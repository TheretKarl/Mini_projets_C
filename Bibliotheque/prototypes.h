#ifndef prototypes
#define prototypes
// fonctions_base.c
int length_str(char *str);
char *create_str(char *str);
int length_file(char *name_file, int max_size);
char **array_str_file(char *name_file, int max_size);
void print_array_str(char **array);
void free_array_str(char **array);
char *create_str_add(char *str1, char *str2, char add);
int check_int(char *integer);
int strint(char *integer, int *i);

typedef struct _str_int{
  char *str;
  int data;
}str_int;

str_int *allocate_str_int(char *str, int data);
void free_str_int(str_int *si);

// fonctions_list.c
typedef struct _list_str{
  struct _list_str *next;
  char *str;
} list_str;

list_str *allocate_list_str(char *str);
list_str *add_list_str(list_str *list, char *str);
void free_list_str(list_str *list);
void print_list_str(list_str *list);
char *remove_list_str(list_str **list, char *str);
char *copy_element_list_str(list_str *list, char*str);
char *pop_list_str(list_str **list);
int element_in_list_str(list_str *list, char *element);

// fonctions_maths.c
int abs_n(int n);
int pow_n(int i, int n);

#endif
