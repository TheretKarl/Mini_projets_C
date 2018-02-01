#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(int argc, char* argv[]){
	srand(time(NULL));
	if(argc < 3){
	  printf("Pas assez d'arguments !");
	  return 0;
	}
	
	char *chaine = create_str_add("files/carac_poisson", argv[1], '/');
	printf("%s\n", chaine);
	bassin *b = allouer_bassin(100, chaine);
	int n;
	for(n = 0; n < 100; n++){
		create_poisson_bassin(b);
	}

	char *name_save = creer_name(argv[2]);
	printf("%s\n name_save");
	pecheur *test = allouer_pecheur_file(name_save);
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
