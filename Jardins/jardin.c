#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "structures.h"
#define MAX_FILE 200

// Fonctions de bases
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

produit_fini *allouer_produit_fini_copy(produit_fini **tableau, char *name){
	int found = find_name(tableau, name);
	if(found != -1){
		produit_fini *copy = NULL;
		copy = allouer_produit_fini(tableau[found]->name, tableau[found]->data);
		if(copy == NULL){
			return NULL;
		}
		return copy;
	}
	return NULL; // Rien ne semble correspondre
}
//

// Les plantes

plante_unique *allouer_plante_unique(char *name, int croissance, char *name_produit){
	plante_unique *plante = NULL;
	plante = (plante_unique *)(malloc(sizeof(plante_unique)));
	if(plante == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	plante->name = creer_name(name);
	plante->croissance = 0;
	plante->croissance_max = croissance;
	plante->name_produit = creer_name(name_produit);
	return plante;
}


void free_plante_unique(plante_unique *plante){
	free(plante->name);
	free(plante->name_produit);
	free(plante);
}

void afficher_plante_unique(plante_unique *plante){
	printf("%s : %d/%d --> %s\n", plante->name, plante->croissance, plante->croissance_max, plante->name_produit);
}

produit_fini *donner_fruit_plante_unique(plante_unique *plante, produit_fini **tableau){
	return allouer_produit_fini_copy(tableau, plante->name_produit);
}

plante_generatrice *allouer_plante_generatrice(char *name, int croissance, char *name_produit, int temps, int timing){
	plante_generatrice *plante = NULL;
	plante = (plante_generatrice *)(malloc(sizeof(plante_generatrice)));
	if(plante == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	plante->name = creer_name(name);
	plante->croissance = 0;
	plante->croissance_max = croissance;
	plante->name_produit = creer_name(name_produit);
	plante->temps_restant = temps;
	plante->timing_actuelle = 0;
	plante->timing = timing;
	return plante;
}

void free_plante_generatrice(plante_generatrice *plante){
	free(plante->name);
	free(plante->name_produit);
	free(plante);
}

void afficher_plante_generatrice(plante_generatrice *plante){
	printf("%s : %d/%d --> %s\n", plante->name, plante->croissance, plante->croissance_max, plante->name_produit);
	if(plante->croissance == plante->croissance_max){
		printf("Prochaine recolte : %d/%d, ", plante->timing_actuelle, plante->timing);
		printf("temps de vie restant : %d", plante->temps_restant);
	}
	printf("\n");
}

produit_fini *donner_fruit_plante_generatrice(plante_generatrice *plante, produit_fini **tableau){
	return allouer_produit_fini_copy(tableau, plante->name_produit);
}

// Les ressources et leur stockage
poche_produit_fini *allouer_poche_produit_fini(produit_fini *product){
	poche_produit_fini *p = NULL;
	p = (poche_produit_fini *)(malloc(sizeof(poche_produit_fini)));
	if(p == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	p->produit = product;
	p->suivant = NULL;
	return p;
}

void afficher_poche_produit_fini(poche_produit_fini *poche){
	if(poche->produit != NULL){
		afficher_produit_fini(poche->produit);
	}
}

void free_poche_produit_fini(poche_produit_fini *poche){
	// Fonction rarement utilisee, elle liberer la poche ET le produit
	if(poche->produit != NULL){
		free_produit_fini(poche->produit);
	}
	free(poche);
}

inventaire_produit_fini *allouer_inventaire_produit_fini(int numero){
	inventaire_produit_fini *i = NULL;
	i = (inventaire_produit_fini *)(malloc(sizeof(inventaire_produit_fini)));
	if(i == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	
	i->numero = numero;
	i->premier = NULL;
	return i;
}

void free_inventaire_produit_fini(inventaire_produit_fini *inv){
	poche_produit_fini *copy = inv->premier;
	poche_produit_fini *copy2 = NULL;
	while(copy != NULL){
		copy2 = copy;
		copy = copy->suivant;
		if(copy2 != NULL){
			free_poche_produit_fini(copy2);
		}
	}
	free(inv);
}

void afficher_inventaire_produit_fini(inventaire_produit_fini *inv){
	poche_produit_fini *copy = inv->premier;
	if(copy == NULL){
		return;
	}
	
	int i = 0;
	while(copy != NULL){
		printf("%d : ", i);
		afficher_poche_produit_fini(copy);
		copy = copy->suivant;
		i++;
	}
}

void ajouter_poche_inventaire_produit_fini(inventaire_produit_fini *inv, poche_produit_fini *poche){
	if(inv->premier == NULL){
		inv->premier = poche;
		return;
	}
	poche_produit_fini *copy = inv->premier;
	while(copy->suivant != NULL){
		copy = copy->suivant;
	}
	copy->suivant = poche;
}

produit_fini *retirer_poche_inventaire_produit_fini(inventaire_produit_fini *inv, char *name){
	// Retire et renvoie la premirer occurence d'un fruit nomme name
	poche_produit_fini *copy = inv->premier;
	poche_produit_fini *copy2 = NULL;
	produit_fini *renvoie = NULL;
	if(inv == NULL){
		return NULL;
	}
	
	while(copy != NULL && renvoie == NULL){
		if(strcmp(copy->produit->name, name) == 0){
			renvoie = copy->produit;
		}
		copy2 = copy; // On garde en memoire celui d'avant
		copy = copy->suivant;
	}
	copy2->suivant = copy->suivant;
	free(copy); // On libere la poche devenu inutile
	return renvoie;
}

inventaire_produit_fini *allouer_inventaire_produit_fini_n(produit_fini **tableau, int n, int numero){
	// Fonctions de generation pseudo-aleatoire d'un inventaire de taille avec un tableau de reference
	inventaire_produit_fini *inv = allouer_inventaire_produit_fini(numero);
	int length = 0; //On calcule la longueur pour generer des nombres dans bon intervalle
	while(tableau[length] != NULL){
		length++;
	}
	
	poche_produit_fini *poche = NULL;
	produit_fini *copy = NULL;
	int i;
	int temp; // Variable aleatoire
	for(i = 0; i < n; i++){
		temp = random_a_b(0, length);
		copy = allouer_produit_fini(tableau[temp]->name, tableau[temp]->data);
		poche = allouer_poche_produit_fini(copy);
		ajouter_poche_inventaire_produit_fini(inv, poche);
	}
	
	return inv;
}
