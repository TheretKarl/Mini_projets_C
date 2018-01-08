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
	
} plante_unique;

typedef struct _plante_generatrice{
	char *name;
	int croissance;
	int croissance_max;
	int temp_restant; // Quand ce nombre atteint 0, la plante meurt
	int timing_actuelle;
	int timing; // Lors actuelle atteint timing, donne un produit_fini
} plante_generatrice;

#endif
