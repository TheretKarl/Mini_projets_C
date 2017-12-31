#ifndef prototypes
#define prototypes

char *creer_name(char *name);
void afficher_name(char *name);
void liberer_name(char *name);
int length_file(char *name_file);
char **tableau_chaines_file(char *name_file);
void afficher_tableau_chaine(char **tableau_chaines);
void liberer_tableau_chaine(char **tableau_chaines);

#endif
