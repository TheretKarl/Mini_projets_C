#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#define MAX_FILE 200

// Fonctions de bases

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

//

// Les produits finis

produit_fini *allouer_produit_fini(char *name, int data){
	produit_fini *f = NULL;
	f = (produit_fini *)(malloc(sizeof(produit_fini)));
	if(f == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	f->name = creer_name(name);
	f->data = data;
	return f;
}

void free_produit_fini(produit_fini *prod){
	free(prod->name);
	free(prod);
}

void afficher_produit_fini(produit_fini *prod){
	printf("%s : %d\n", prod->name, prod->data);
}

produit_fini *allouer_produit_fini_file(char *name_file){
	// Alloue un produit fini a partir d'un fichier portant ce nom
	// Pour plus d'information, lire README.md
	
	FILE *file = NULL;
	file = fopen(name_file, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	char name[MAX_FILE] = "";
	char *chaine;
	int data = 0;
	
	fgets(name, MAX_FILE,file);
	chaine = creer_name(name);
	fscanf(file, "%d", &data);
	fclose(file);
	
	return allouer_produit_fini(name, data);
}

produit_fini **allouer_tableau_produit_fini(char *file_name){
	char **tab = tableau_chaines_file(file_name);
	int length = 0; // On calcule la longueur
	while(tab[length] != NULL){
		length++;
	}
	
	produit_fini **tableau_produit = NULL;
	tableau_produit = (produit_fini **)(malloc(sizeof(produit_fini *) * (length + 1)));
	if(tableau_produit == NULL){
		free_tableau_chaines_file(tab);
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	int i;
	for(i = 0; i < length; i++){
		// On le remplit en correspondant au tableau
		tableau_produit[i] = allouer_produit_fini_file(tab[i]);
	}
	// Le dernier element est NULL pour signifier la fin
	tableau_produit[i] = NULL;
	
	free_tableau_chaines_file(tab); // On oublie pas de liberer le tableau
	return tableau_produit;
}

void afficher_tableau_produit_fini(produit_fini **tableau){
	int i = 0;
	while(tableau[i] != NULL){
		afficher_produit_fini(tableau[i]);
		i++;
	}
}

void free_tableau_produit_fini(char **tableau){
	int i = 0;
	while(tableau[i] != NULL){
		free(tableau[i]);
		i++;
	}
	free(tableau);
}

int find_name(produit_fini **tableau, char *name){
	int i = 0;
	while(tableau[i] != NULL){
		if(strcmp(tableau[i]->name, name) == 0){
			return i;
		}
		i++;
	}
	return -1;
}
//
