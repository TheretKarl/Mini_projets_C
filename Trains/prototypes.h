#ifndef prototypes
#define prototypes

// Fonctions de base
char *creer_name(char *name);
void afficher_name(char *name);
void liberer_name(char *name);
int random_a_b(int a, int b);

// Fonctions de creation de ligne et de station
Ligne *creer_ligne(char *name);
Station *creer_station(char *name, int a, int b); // Cree une station avec un nom (max de personnes entre a et b)
Ligne *ajouter_station_ligne_en_tete(Station *s, Ligne *l);
Ligne *ajouter_station_ligne_en_queue(Station *s, Ligne *l);
void afficher_ligne(Ligne *l);
void liberer_ligne(Ligne *l);
Ligne *creer_ligne_avec_fichier(char *name, char *nom_fichier, int a, int b);

// Fonctions de creation des trains
Wagon *creer_wagon(int place); // Alloue un wagon avec n places
void ajouter_wagon_train(Train *t, Wagon *w);
Train *creer_train(int place, int longueur); // La place par wagon et le nombre de wagons
void mettre_train_en_ligne(Train *t, Ligne *l); // Donner une ligne au train
void mettre_train_en_ligne_n(Train *t, Ligne *l, int n); // Place le terrain selon n
void liberer_train(Train *t);
void afficher_etat_train(Train *t);

// Fonctions de gestion des passagers et de deplacement du train
int compter_wagon_libre(Wagon *w);
int compter_train_libre(Train *t);
void train_move(Train *t);
void train_deposer_passagers(Train *t);
void train_prendre_passagers(Train *t);
void train_action(Train *t);

// Fonctions de remplissage des quais
void remplir_station(Station *s);
void remplir_ligne(Ligne *l);

// Fonctions de simulation de ligne et des trains
 
#endif
