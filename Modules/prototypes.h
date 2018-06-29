#ifndef prototypes
#define prototypes

// Fonctions de base
int length_str(char *str);
int random_a_b(int a, int b);
char *create_name(char *chaine);
int file_length(char *file_name);
char **array_str_file(char *name_file);
void print_array_str(char **tableau_chaines);
void free_array_str_file(char **tableau_chaine);
char *create_str_add(char *str1, char *str2, char add);

// Les fonctions de modules et de creation
list_char *allocation_list_char(char character);
void add_list_char(list_char **list, list_char *add);
char pop_list_char(list_char **list);
void print_list_char(list_char *list);
void free_list_char(list_char *list);
list_str *allocation_list_str(char *str);
void add_list_str(list_str **list, list_str *add);
char *pop_list_str(list_str **list_str);
module *allocation_module(int energy, int speed);
void module_set_destination(module **who, char *destination);
void module_find_way(module **who);
point *create_point(char *name, int x, int y);
void free_point(point *p);



#endif
