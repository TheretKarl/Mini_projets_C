#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

#include <unistd.h>
#define N 30

int main(){
	srand(time(NULL));
	
	/* Station *s1 = creer_station("Villiers", 10, 50);
	Station *s2 = creer_station("Sarcelles", 30, 100);
	Station *s3 = creer_station("Pierre",10,30);
	Ligne *ma_ligne = creer_ligne("RER D");
	ma_ligne = ajouter_station_ligne_en_queue(s1, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_queue(s2, ma_ligne);
	ma_ligne = ajouter_station_ligne_en_tete(s3, ma_ligne);
	afficher_ligne(ma_ligne);
	liberer_ligne(ma_ligne);
	
	*/
	Ligne *ma_ligne_fichier = creer_ligne_avec_fichier("RER D", "RED_D.txt", 50, 100);
	Train *my_train = creer_train(10, 5);
	mettre_train_en_ligne(my_train, ma_ligne_fichier);
	/*Train *numero_2 = creer_train(15, 10);
	mettre_train_en_ligne_n(my_train, ma_ligne_fichier, 20);*/
	Train *t2 = creer_train(15,20);
	mettre_train_en_ligne(t2, ma_ligne_fichier);
	
	int i = 0;
	printf("Debut de la simulation !");
	while(i <= N){
		printf("%d\n", i);
		afficher_etat_train(my_train);
		//afficher_etat_train(numero_2);
		afficher_etat_train(t2);
		remplir_ligne(ma_ligne_fichier);
		train_action(my_train);
		train_action(t2);
		usleep(1000000);
		i++;
	}
	liberer_train(my_train);
	liberer_ligne(ma_ligne_fichier);
	return 0;
}
