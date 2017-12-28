#ifndef prototypes
#define prototypes

char *creer_name(char *name);
void afficher_name(char *name);
void liberer_name(char *name);
int random_a_b(int a, int b);
Station *creer_station(char *name); // Cree une station avec un nom
Ligne ajouter_station_ligne_en_tete(Station *s, Ligne l);
Ligne ajouter_station_ligne_en_queue(Station *s, Ligne l);
void afficher_ligne(Ligne l);
void liberer_ligne(Ligne l);

#endif
