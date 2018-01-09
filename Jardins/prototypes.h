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

// Les produits fini
produit_fini *allouer_produit_fini(char *name, int data);
void free_produit_fini(produit_fini *prod);
void afficher_produit_fini(produit_fini *prod);
produit_fini *allouer_produit_fini_file(char *name_file);
produit_fini **allouer_tableau_produit_fini(char *file_name);
void afficher_tableau_produit_fini(produit_fini **tableau);
void free_tableau_produit_fini(produit_fini **tableau);
int find_name(produit_fini **tableau, char *name);
produit_fini *allouer_produit_fini_copy(produit_fini **tableau, char *name);

// Les "createurs" de produit finis

// -- Plante unique
plante_unique *allouer_plante_unique(char *name, int croissance, char *name_produit);
void free_plante_unique(plante_unique *plante);
void afficher_plante_unique(plante_unique *plante);
produit_fini *donner_fruit_plante_unique(plante_unique *plante, produit_fini **tableau);

// -- Plante Generatrice
plante_generatrice *allouer_plante_generatrice(char *name, int croissance, char *name_produit, int temps, int timing);
void free_plante_generatrice(plante_generatrice *plante);
void afficher_plante_generatrice(plante_generatrice *plante);
produit_fini *donner_fruit_plante_generatrice(plante_generatrice *plante, produit_fini **tableau);

// Les ressources et leur stockage
poche_produit_fini *allouer_poche_produit_fini(produit_fini *product);
void afficher_poche_produit_fini(poche_produit_fini *poche);
void free_poche_produit_fini(poche_produit_fini *poche);
inventaire_produit_fini *allouer_inventaire_produit_fini(int numero);
void afficher_inventaire_produit_fini(inventaire_produit_fini *inv);
void free_inventaire_produit_fini(inventaire_produit_fini *inv);
void ajouter_poche_inventaire_produit_fini(inventaire_produit_fini inv, poche_produit_fini poche);
produit_fini retirer_poche_inventaire_produit_fini(inventaire_produit_fini, char *name);
inventaire_produit_fini *allouer_inventaire_produit_fini_n(produit_fini **tableau, int n, int numero);

// Gestion de l'environnement
plante *allouer_plante(plante_unique *p1, plante_generatrice *p2);
void free_plante(plante *p);
void afficher_plante(plante *p);
plante **tableau_plante(int longueur);
void free_tableau_plante(plante **tab, int longueur);
rangee *creer_rangee(int longueur);
int planter_rangee(rangee *r, plante *p, int indice);
void free_rangee(rangee *r);
void afficher_rangee(rangee *r);
plante *allouer_plante_file(char *name_file);
plante **allouer_tableau_plante(char *file_name);
void afficher_tableau_plante(plante **tab);

// Liste des donnees
donnee_ref *allouer_tableau_reference(char *prod, char *plantes);
void afficher_tableau_ref(donnee_ref *ref);
void free_tableau_ref(donnee_ref *ref);

#endif
