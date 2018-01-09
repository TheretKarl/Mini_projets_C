#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include <time.h>
#define MAX_FILE 200

int random_a_b(int a, int b){
	// Renvoie un nombre entra et b exclu
	return rand()%(b-a) + a;
}

char *creer_name(char *name){
	// On calcule d'abord la longueur de la chaine (sans les retour a la ligne)
	int i =0;
	while(name[i] != '\0' && name[i] != '\n'){
		i++;
	}
	char *s = (char*)(malloc(sizeof(char) * (i + 1)));
	if(s == NULL){
		printf("Erreur survenue lors de l'allocation !");
		return NULL;
	}
	int j;
	for(j = 0; j < i; j++){
		s[j] = name[j];
	}
	s[i] = '\0';
	return s;
}

void liberer_name(char *name){
	free(name);
}

int length_file(char *name_file){
	// Renvoie le nombre de lignes dans le fichier
	
	FILE* file = NULL;
	file = fopen(name_file, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	int i = 0;
	char chaine[MAX_FILE] = "";
	while(fgets(chaine, MAX_FILE, file) != NULL){
		i++;
	}
	fclose(file);
	
	return i;
}

char **tableau_chaines_file(char *name_file){
	// On calcule le nombre de chaine
	int length = length_file(name_file);
	
	// On cree tableau de chaines (avec le dernier element en NULL
	char **tableau_chaines = (char **)(malloc(sizeof(char *) * length + 1));
	
	FILE* file = NULL;
	file = fopen(name_file, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		free(tableau_chaines);
		return NULL;
	}
	
	int i = 0;
	char *copy_chaine = NULL;
	char chaine[MAX_FILE] = "";
	while(fgets(chaine, MAX_FILE, file) != NULL){
		copy_chaine = creer_name(chaine);
		tableau_chaines[i] = copy_chaine;
		i++;
	}
	fclose(file);
	tableau_chaines[i] = NULL; // le dernier element est NULL, pour signaler la fin
	
	return tableau_chaines;
}

void afficher_tableau_chaine(char **tableau_chaines){
	int i = 0;
	while(tableau_chaines[i] != NULL){
		printf("%s\n", tableau_chaines[i]);
		i++;
	}
}

void free_tableau_chaines_file(char **tableau_chaine){
	int i = 0 ;
	while(tableau_chaine[i] != NULL){
		liberer_name(tableau_chaine[i]);
		i++;
	}
	free(tableau_chaine[i]);
	free(tableau_chaine);
}

// Les caracteristiques d'un poisson
carac_poisson *allouer_carac_poisson(char *name, char *gout, int min, int max, int valeur, int resistance){
	carac_poisson *ca = NULL;
	ca = (carac_poisson *)(malloc(sizeof(carac_poisson)));
	if(ca == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	ca->name = creer_name(name);
	ca->gout = creer_name(gout);
	ca->taille_min = min;
	ca->taille_max = max;
	ca->valeur = valeur;
	ca->resistance = resistance;
	
	return ca;
}

carac_poisson *allouer_carac_poisson_file(char *file_name){
	// On ouvre le fichier et on place les caracteristiques
	FILE* file = NULL;
	file = fopen(file_name, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	int i1,i2,i3,i4; // Pour les autre entiers
	char chaine[MAX_FILE] = "";
	char *copy1; char *copy2;

	// On recupere
	fgets(chaine, MAX_FILE, file);
	copy1 = creer_name(chaine);
	fgets(chaine, MAX_FILE, file);
	copy2 = creer_name(chaine);
	fscanf(file, "%d %d %d %d", &i1, &i2, &i3, &i4);
	
	fclose(file);
	
	// On cree en placant les bonnes informations
	carac_poisson *ca = NULL;
	ca = allouer_carac_poisson(copy1, copy2, i1, i2, i3, i4);
	liberer_name(copy1);
	liberer_name(copy2);
	
	return ca;
}

void afficher_carac_poisson(carac_poisson *ca){
	printf("%s : (%d -- %d), valeur %d et resistance %d. Gout : %s\n", 
		ca->name, ca->taille_min, ca->taille_max, ca->valeur, ca->resistance, ca->gout);
}

void free_carac_poisson(carac_poisson *ca){
	liberer_name(ca->name);
	liberer_name(ca->gout);
	free(ca);
}

carac_poisson **allouer_ref_carac_poisson(char *file_name){
	int length = length_file(file_name);
	char **tab_files = tableau_chaines_file(file_name);
	
	carac_poisson **ref_carac = NULL;
	ref_carac = (carac_poisson **)(malloc(sizeof(carac_poisson *) * (length + 1)));
	if(ref_carac == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	int i;
	for(i = 0 ; i < length; i++){
		ref_carac[i] = allouer_carac_poisson_file(tab_files[i]);	
	}
	ref_carac[i] = NULL;
	return ref_carac;
}

void afficher_ref_carac_poisson(carac_poisson **tab){
	int i = 0;
	while(tab[i] != NULL){
		afficher_carac_poisson(tab[i]);
		i++;
	}
}

void free_ref_carac_poisson(carac_poisson **tab){
	int i = 0;
	while(tab[i] != NULL){
		free_carac_poisson(tab[i]);
		i++;
	}
	free(tab);
}

// Les poissons
int indice_poisson(char *name, carac_poisson **tab){
	// Trouve l'indice du poisson portant ce nom
	char *copy = creer_name(name);
	int i = 0;
	
	while(tab[i] != NULL){
		if(strcmp(tab[i]->name, copy) ==  0){
			liberer_name(copy);
			return i;
		}
		i++;
	}
	
	liberer_name(copy);
	return -1;
}

poisson *allouer_poisson(char *name, carac_poisson **tab){
	int i = indice_poisson(name, tab);
	
	if(i == -1){
		return NULL;
	}
	
	poisson *p = NULL;
	p = (poisson *)(malloc(sizeof(poisson)));
	if(p == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	p->name = creer_name(tab[i]->name);
	p->gout = creer_name(tab[i]->gout);
	p->taille = random_a_b(tab[i]->taille_min, tab[i]->taille_max + 1);
	p->valeur = tab[i]->valeur;
	p->resistance = tab[i]->resistance;
	
	return p;
}

void afficher_poisson(poisson *p){
	printf("%s : %d de taille, valeur %d et resistance %d. Gout : %s\n", 
		p->name, p->taille, p->valeur, p->resistance, p->gout);
}

void free_poisson(poisson *p){
	liberer_name(p->name);
	liberer_name(p->gout);
	free(p);
}
