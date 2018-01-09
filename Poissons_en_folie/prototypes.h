#ifndef prototypes
#define prototypes

// Fonctions de base
int random_a_b(int a, int b);
char *creer_name(char *chaine);
void liberer_name(char *name);
int file_length(char *file_name);
char **tableau_chaines_file(char *name_file);
void afficher_tableau_chaine(char **tableau_chaines);
void free_tableau_chaines_file(char **tableau_chaine);
int random_a_b(int a, int b);

// Les caracteristiques d'un poisson
carac_poisson *allouer_carac_poisson(char *name, char *gout, int min, int max, int valeur, int resistance);
carac_poisson *allouer_carac_poisson_file(char *file_name);
void afficher_carac_poisson(carac_poisson *ca);
void free_carac_poisson(carac_poisson *ca);
carac_poisson **allouer_ref_carac_poisson(char *file_name);
void afficher_ref_carac_poisson(carac_poisson **tab);
void free_ref_carac_poisson(carac_poisson **tab);

// Les poissons
// Note : un poisson n'est cree uniquement en fonction d'un tableau avec ses caracteristiques
int indice_poisson(char *name, carac_poisson **tab);
poisson *allouer_poisson(char *name, carac_poisson **tab);
void afficher_poisson(poisson *p);
void free_poisson(poisson *p);

#endif
