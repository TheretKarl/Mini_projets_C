#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	srand(time(NULL));
	Station *s1 = creer_station("Villiers", 10, 50);
	Station *s2 = creer_station("Sarcelles", 30, 100);
	Station *s3 = creer_station("Pierre",10,30);
	Ligne *ma_ligne = creer_ligne("RER D");
	ma_ligne = ajouter_station_ligne_en_queue(s1, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_queue(s2, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_tete(s3, ma_ligne);
	afficher_ligne(ma_ligne);
	liberer_ligne(ma_ligne);
	
	Ligne *ma_ligne_fichier = creer_ligne_avec_fichier("RER D", "RED_D.txt", 50, 100);
	afficher_ligne(ma_ligne_fichier);
	liberer_ligne(ma_ligne_fichier);
	return 0;
}
