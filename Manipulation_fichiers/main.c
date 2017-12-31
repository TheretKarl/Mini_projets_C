#include <stdio.h>
#include <stdlib.h>
#include "prototypes.h"

int main(){
	char **mon_tableau = tableau_chaines_file("fichiers.txt");
	afficher_tableau_chaine(mon_tableau);
	liberer_tableau_chaine(mon_tableau);
	return 0;
}
