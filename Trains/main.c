#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	srand(time(NULL));
	// Phase de test 1
	Personne p;
	p.type = 5;
	printf("%d\n", p.type);
	Station *s = NULL;
	char *name = creer_name("chaine");
	afficher_name(name);
	liberer_name(name);
	printf(" --- \n\n");
	
	// Phase de test 2
	Ligne metro_7;
	metro_7.premier = NULL;
	metro_7.dernier = NULL;
	metro_7.name = creer_name("Metro 7");
	afficher_ligne(metro_7);
	Station *s1 = creer_station("Waterloo");
	Station *s2 = creer_station("Paris Nord");
	Station *s3 = creer_station("Châtelet");
	Station *s4 = creer_station("Paris Lyon");
	metro_7 = ajouter_station_ligne_en_tete(s1, metro_7);
	metro_7 = ajouter_station_ligne_en_tete(s2, metro_7);
	//metro_7 = ajouter_station_ligne_en_queue(s3, metro_7);
	metro_7 = ajouter_station_ligne_en_tete(s4, metro_7);
	afficher_ligne(metro_7);
	liberer_ligne(metro_7);
	printf(" --- \n\n");
	// Phase de test 3
	return 0;
}
