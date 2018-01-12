#ifndef prototypes
#define prototypes

// Fonctions de base
int length_str(char *str);
int random_a_b(int a, int b);
char *creer_name(char *chaine);
void liberer_name(char *name);
int file_length(char *file_name);
char **tableau_chaines_file(char *name_file);
void afficher_tableau_chaine(char **tableau_chaines);
void free_tableau_chaines_file(char **tableau_chaine);
char *create_str_add(char *str1, char *str2, char add);

// Les caracteristiques d'un poisson
carac_poisson *allouer_carac_poisson(char *name, char *gout, int min, int max, int valeur, int resistance);
carac_poisson *allouer_carac_poisson_file(char *file_name);
void afficher_carac_poisson(carac_poisson *ca);
void free_carac_poisson(carac_poisson *ca);
carac_poisson **allouer_ref_carac_poisson(char *file_name);
void afficher_ref_carac_poisson(carac_poisson **tab);
void free_ref_carac_poisson(carac_poisson **tab);

// Les poissons
int indice_poisson(char *name, carac_poisson **tab);
poisson *allouer_poisson(char *name, carac_poisson **tab);
void afficher_poisson(poisson *p);
void free_poisson(poisson *p);
poisson *allouer_poisson_file(char *name, char *gout, int taille, int valeur, int resistance);

// L'inventaire et stock
liste_poisson *allouer_liste_poisson(poisson *p);
void free_liste_poisson(liste_poisson *l);
liste_poisson *add_poisson_liste(liste_poisson *l, poisson *p);
void afficher_liste_poisson(liste_poisson *l);
liste_poisson *remove_element_liste_poisson(liste_poisson *l, char *name, poisson **p);

char **allouer_names_fish(carac_poisson **ref);
void free_names_fish(char **names_fish);
poisson **allouer_stock_poisson(int taille);
void free_stock_poisson(poisson **stock, int taille);
bassin *allouer_bassin(int taille, char *ref);
void free_bassin(bassin *b);
int indice_bassin_libre(bassin *b);
char *random_name(char **names);
void create_poisson_bassin(bassin *b);
void afficher_bassin(bassin *b);
int compter_poisson_bassin(bassin *b);

// Le pecheur et les actions possibles
pecheur *allouer_pecheur(char *name, int energie, int argent);
void free_pecheur(pecheur *p);
void add_poisson_pecheur(pecheur *fisher, poisson *fish);
void remplir_poissons_pecheur(pecheur *p, char *name_file);
pecheur *allouer_pecheur_file(char *save);
int compter_poisson_pecheur(pecheur *p);
void afficher_pecheur(pecheur *p);
poisson *bassin_poisson(bassin *b);
void pecher_poisson_bassin(pecheur *p, bassin *b);
void vendre_poisson(pecheur *p, char *name_poisson);

// Les options de sauvegarde
int save_pecheur(pecheur *p, char *file_name);
int save_poissons(pecheur *p, char *file_name);
void save_game(pecheur *p, char *save);
void new_game(char *save);

#endif
