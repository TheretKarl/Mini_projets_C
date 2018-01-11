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

typedef struct _liste_poisson{
	poisson *fish;
	struct _liste_poisson *suivant;
}liste_poisson;

typedef struct _bassin{
	poisson **stock; // Ceux dans le bassin(tableau)
	int taille; // du bassin
	carac_poisson **reference;
	char **names_fish;
}bassin;

typedef struct _pecheur{
	char *name;
	liste_poisson *l;
	int argent;
	int energie; // L'energie qu'il reste
	int energie_max;
}pecheur;
#endif
