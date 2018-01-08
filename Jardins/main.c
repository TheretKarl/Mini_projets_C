#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"

int main(){
	produit_fini **tab = allouer_tableau_produit_fini("files/produit_fini/liste.txt");
	afficher_tableau_produit_fini(tab);
	char *try = "tomate";
	printf("%d\n", find_name(tab, try));
	char *try2 = "haricot";
	printf("%d\n", find_name(tab, try2));
	char *try3 = "grenade";
	printf("%d\n", find_name(tab, try3));
	free_tableau_produit_fini(tab);
	
	return 0;
}
