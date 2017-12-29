#ifndef prototypes
#define prototypes

// Fonctions de base
char *creer_name(char *name);
void afficher_name(char *name);
void liberer_name(char *name);
int random_a_b(int a, int b);

// Fonctions de creation de ligne et de station
Ligne *creer_ligne(char *name);
Station *creer_station(char *name); // Cree une station avec un nom
Ligne *ajouter_station_ligne_en_tete(Station *s, Ligne *l);
Ligne *ajouter_station_ligne_en_queue(Station *s, Ligne *l);
void afficher_ligne(Ligne *l);
void liberer_ligne(Ligne *l);

// Fonctions de creation des trains
Wagon *creer_wagon(int place); // Alloue un wagon avec n places
void *ajouter_wagon_train(Train *t, Wagon *w);
Train *creer_train(int place, int longueur); // La place par wagon et le nombre de wagons
void mettre_train_en_ligne(Train *t, Ligne *l); // Donner une ligne au train
void liberer_train(Train *t);
void afficher_etat_train(Train *t);
#endif
