#ifndef structures
#define structures

typedef struct _carac_poisson{
	char *name;
	char *gout;
	int taille_min;
	int taille_max;
	int valeur;
	int resistance; // La facilite a etre attrapre
}carac_poisson;

typedef struct _poisson{
	char *name;
	char *gout;
	int taille;
	int valeur;
	int resistance; // La facilite a etre attrapre
}poisson;
#endif
