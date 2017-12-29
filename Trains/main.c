#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

#include <unistd.h>
#define N 60

int main(){
	srand(time(NULL));
	Ligne *ma_ligne_fichier = creer_ligne_avec_fichier("RER D", "RED_D.txt", 50, 100);
	Train *my_train = creer_train(10, 5);
	mettre_train_en_ligne(my_train, ma_ligne_fichier);
	Train *t2 = creer_train(15,20);
	mettre_train_en_ligne(t2, ma_ligne_fichier);
	Train *t3 = creer_train(10,25);
	mettre_train_en_ligne(t3, ma_ligne_fichier);
	
	int i = 0;
	printf("Debut de la simulation !");
	while(i <= N){
		printf("%d\n", i);
		afficher_etat_ligne(ma_ligne_fichier);
		afficher_etat_train(my_train);
		afficher_etat_train(t2);
		afficher_etat_train(t3);
		remplir_ligne(ma_ligne_fichier);
		train_action(my_train);
		train_action(t2);
		train_action(t3);
		usleep(500000);
		i++;
	}  
	liberer_train(my_train);
	liberer_train(t2);
	liberer_train(t3);
	liberer_ligne(ma_ligne_fichier);
	return 0;
}
