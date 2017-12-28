#ifndef structures
#define structures

// Une personne se definit par la destination qu'elle veut atteindre (entier entre 0 et x)
typedef struct _personnne{
	int type;
} Personne;

// Une station possede un nom et un nombre de personne en attente, de plus qu'un type(entier entre 0 et x)
typedef struct _station{
	int type; 
	char *name;
	Personne nb_personnes[50]; // Cinquante personne maximun
	struct _station *precedent;
	struct _station *suivant;
} Station;

typedef struct _ligne{
	char *name;
	Station *premier;
	Station *dernier;
} Ligne;

#endif
