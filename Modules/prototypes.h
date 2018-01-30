#ifndef prototypes
#define prototypes

// Fonctions de base
int length_str(char *str);
int random_a_b(int a, int b);
char *create_name(char *chaine);
void free_name(char *name);
int file_length(char *file_name);
char **tableau_chaines_file(char *name_file);
void print_tableau_chaine(char **tableau_chaines);
void free_tableau_chaines_file(char **tableau_chaine);
char *create_str_add(char *str1, char *str2, char add);

#endif
