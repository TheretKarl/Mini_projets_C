#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(){
	char **tab = tableau_chaines_file("fichier_test.txt");
	print_tableau_chaine(tab);
	free_tableau_chaines_file(tab);
	return 0;
}
