#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(){
	srand(time(NULL));
	
	bassin *b = allouer_bassin(20, "files/carac_poisson/liste.txt");
	int n;
	for(n = 0; n < 20; n++){
		create_poisson_bassin(b);
	}
	//afficher_bassin(b);
	
	pecheur *test = allouer_pecheur_file("Univers");
	afficher_pecheur(test);
	
	for(n = 0; n < 100; n++){
		pecher_poisson_bassin(test, b);
	}
	
	afficher_pecheur(test);
	afficher_bassin(b);
	free_bassin(b);
	save_game(test, "Univers");
	free_pecheur(test);

	return 0;
}
