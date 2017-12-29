#ifndef structures
#define structures

// Une station possede un nom et un nombre de personne en attente, de plus qu'un type(entier entre 1 et 4)
typedef struct _station{
	int type; // Influe sur le nombre de personnes qui descendent sur la station
	char *name; // Dynamiquement
	int nb_personnes; // Nombre de personnes sur le quai
	int nb_max_personnes; 
	struct _station *precedent;
	struct _station *suivant;
} Station;

typedef struct _ligne{
	char *name; // Dynamiquement
	Station *premier;
	Station *dernier;
} Ligne;

// Simplement chainees, suit le prochain dans la liste
typedef struct _wagon{
	struct _wagon *suivant;
	int nb_personnes; // Le nombre de personnes dans ce wagon
	int nb_max_personnes;
} Wagon;

// Un train est suivi par une liste chainee de wagons et appartient a une ligne, en plus d'une position actuelle
typedef struct _train{
	Wagon *premier;
	Ligne *ligne;
	Station *actuelle;
	int direction; // Elle vaut 0 ou 1, selon la direction
} Train;

#endif
