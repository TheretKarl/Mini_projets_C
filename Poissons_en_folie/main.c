#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include "prototypes.h"
#include <time.h>

int main(){
	srand(time(NULL));
	
	carac_poisson **ref = allouer_ref_carac_poisson("files/carac_poisson/liste.txt");
	afficher_ref_carac_poisson(ref);
	
	poisson *p = allouer_poisson("sardine", ref);
	afficher_poisson(p);
	free_poisson(p);
	
	free_ref_carac_poisson(ref);
	return 0;
}
