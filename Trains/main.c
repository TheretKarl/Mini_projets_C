#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	srand(time(NULL));
	Station *s1 = creer_station("Villiers");
	Station *s2 = creer_station("Sarcelles");
	Station *s3 = creer_station("Pierre");
	Ligne *ma_ligne = creer_ligne("RER D");
	ma_ligne = ajouter_station_ligne_en_queue(s1, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_queue(s2, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_tete(s3, ma_ligne);
	afficher_ligne(ma_ligne);
	liberer_ligne(ma_ligne);
	return 0;
}
