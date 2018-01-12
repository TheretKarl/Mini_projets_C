#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(){
	srand(time(NULL));
	
	bassin *b = allouer_bassin(100, "files/carac_poisson/liste.txt");
	int n;
	for(n = 0; n < 100; n++){
		create_poisson_bassin(b);
	}
	
	//new_game("my_game");
	pecheur *test = allouer_pecheur_file("my_game");
	afficher_pecheur(test);
	
	for(n = 0; n < 30; n++){
		pecher_poisson_bassin(test, b);
	} 
	
	afficher_pecheur(test);
	free_bassin(b);
	for(n = 0; n < 30; n++){
		vendre_poisson(test, "sardine");
	}
	afficher_pecheur(test);
	save_game(test, "my_game");
	free_pecheur(test);
	return 0;
}
