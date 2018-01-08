#ifndef prototypes
#define prototypes

// Fonctions de base
char *creer_name(char *chaine);
void liberer_name(char *name);
int file_length(char *file_name);
char **tableau_chaines_file(char *name_file);
void afficher_tableau_chaine(char **tableau_chaines);
void free_tableau_chaines_file(char **tableau_chaine);

// Les produits fini
produit_fini *allouer_produit_fini(char *name, int data);
void free_produit_fini(produit_fini *prod);
void afficher_produit_fini(produit_fini *prod);
produit_fini *allouer_produit_fini_file(char *name_file);
produit_fini **allouer_tableau_produit_fini(char *file_name);
void afficher_tableau_produit_fini(produit_fini **tableau);
void free_tableau_produit_fini(produit_fini **tableau);
int find_name(produit_fini **tableau, char *name);


// Les "createurs" de produit finis



#endif
