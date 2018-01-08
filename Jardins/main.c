#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	srand(time(NULL)); // La graine de l'aleatoire
	produit_fini **tab = allouer_tableau_produit_fini("files/produit_fini/liste.txt");
	afficher_tableau_produit_fini(tab);
	char *try = "tomate";
	printf("%d\n", find_name(tab, try));
	char *try2 = "haricot";
	printf("%d\n", find_name(tab, try2));
	char *try3 = "grenade";
	printf("%d\n", find_name(tab, try3));
	
	produit_fini *ma_tomate = allouer_produit_fini_copy(tab, "tomate");
	afficher_produit_fini(ma_tomate);
	free_produit_fini(ma_tomate);
	
	plante_unique *ma_plante = allouer_plante_unique("tomatier", 10, "tomate");
	afficher_plante_unique(ma_plante);
	produit_fini *product = donner_fruit_plante_unique(ma_plante, tab);
	afficher_produit_fini(product);
	free_produit_fini(product);
	free_plante_unique(ma_plante);
	
	plante_generatrice *v2 = allouer_plante_generatrice("haricotier", 4, "haricot", 20, 4);
	afficher_plante_generatrice(v2);
	v2->croissance = 4;
	afficher_plante_generatrice(v2);
	produit_fini *prod2 = donner_fruit_plante_generatrice(v2, tab);
	free(v2);
	afficher_produit_fini(prod2);
	poche_produit_fini *ma_poche = allouer_poche_produit_fini(prod2);
	free_poche_produit_fini(ma_poche);
	//free_produit_fini(prod2);
		
	printf("\n###\n");
	
	inventaire_produit_fini *inv = allouer_inventaire_produit_fini_n(tab, 20, 0);
	afficher_inventaire_produit_fini(inv);
	free_inventaire_produit_fini(inv);
	
	free_tableau_produit_fini(tab);
	
	return 0;
}
