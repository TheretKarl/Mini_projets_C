#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	srand(time(NULL)); // La graine de l'aleatoire
	
	plante **les_plantes = allouer_tableau_plante("files/plante/liste.txt");
	afficher_tableau_plante(les_plantes);
	free_tableau_plante(les_plantes, 2);
	
	printf(" --- \n");
	
	donnee_ref *ref = allouer_tableau_reference("files/produit_fini/liste.txt", "files/plante/liste.txt");
	afficher_tableau_ref(ref);
	free_tableau_ref(ref);
	
	return 0;
}
