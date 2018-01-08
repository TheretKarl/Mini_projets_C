#ifndef structures
#define structures

typedef struct _produit_fini{
	char *name;
	int data;
} produit_fini;

typedef struct _plante_unique{
	// Lorsque la croissance atteint le max, la plante donne les produit_fini puis meurt
	char *name;
	int croissance;
	int croissance_max; 
	char *name_produit;
} plante_unique;

typedef struct _plante_generatrice{
	char *name;
	int croissance;
	int croissance_max;
	char *name_produit;
	int temps_restant; // Quand ce nombre atteint 0, la plante meurt
	int timing_actuelle;
	int timing; // Lors actuelle atteint timing, donne un produit_fini
} plante_generatrice;

typedef struct _poche_produit_fini{
	// Inventaire de produits fini
	// Une poche a un element et une reference au suivant
	produit_fini *produit;
	struct _poche_produit_fini *suivant;
}poche_produit_fini;

typedef struct _inventaire_produit_fini{
	int numero; // Le numero de l'inventaire (Inventaire n°n)
	poche_produit_fini *premier;
}inventaire_produit_fini;

#endif
