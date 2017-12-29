#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

// Les Fonctions de base

char *creer_name(char *name){
	// On calcule d'abord la longueur de la chaine
	int i =0;
	while(name[i] != '\0'){
		i++;
	}
	char *s = (char*)(malloc(sizeof(char) * (i + 1)));
	if(s == NULL){
		printf("Erreur survenue lors de l'allocation !");
		return NULL;
	}
	int j;
	for(j = 0; j <= i; j++){
		s[j] = name[j];
	}
	return s;
}

void afficher_name(char *name){
	int i = 0;
	while(name[i] != '\0'){
		printf("%c",name[i]);
		i++;
	}
	printf("\n");
}

void liberer_name(char *name){
	free(name);
}

int random_a_b(int a, int b){
	// Renvoie un nombre entra et b exclu
	return rand()%(b-a) + a;
}

// Les Fonctions de creation de ligne et de stations

Ligne *creer_ligne(char *name){
	Ligne *l = (Ligne *)(malloc(sizeof(Ligne)));
	if(l == NULL){
		printf("Erreur lors de l'allocation !");
		return NULL;
	}
	l->name = creer_name(name);
	l->premier = NULL;
	l->dernier = NULL;
	return l;
}

Station *creer_station(char *name, int a, int b){
	Station *s = (Station*)(malloc(sizeof(Station)));
	if(s == NULL){
		printf("Une erreur est survenue lors de l'allocation !\n");
		return NULL;
	}
	s->type = random_a_b(0,4);
	s->nb_max_personnes = random_a_b(a,b + 1);
	s->nb_personnes = 0;
	s->name = creer_name(name);
	// Il y a initialement 0 personnes sur le quai
	return s;
}

Ligne *ajouter_station_ligne_en_tete(Station *s, Ligne *l){
	Station *s2 = l->premier; // On sauvegarde
	l->premier = s; // On place au debut
	l->premier->suivant = s2; // On fait reference au suivant
	if(s2 != NULL){
		s2->precedent = s;
	}
	if(l->dernier == NULL){
		l->dernier = s;
	}
	return l;
}

Ligne *ajouter_station_ligne_en_queue(Station *s, Ligne *l){
	Station *s2 = l->dernier; // On sauvegarde
	l->dernier = s; // On le place a la fin
	s->precedent = s2; // On fait reference au precedent
	if(s2 != NULL){
		s2->suivant = s;
	}
	if(l->premier == NULL){
		l->premier = s;
	}
	return l;
}

void afficher_ligne(Ligne *l){
	Station *s = l->premier; // On prends le premier arret
	afficher_name(l->name);
	if(s == NULL){
		printf("Ligne vide !\n");
		return;
	}
	while(s->suivant != NULL){
		printf("o-");
		s = s->suivant; // On passe au suivant
	}
	printf("o\n");
}

void liberer_ligne(Ligne *l){
	Station *s1 = l->premier;
	Station *s2;
	while(s1 != NULL){
		s2 = s1; // On garde en memoire
		s1 = s1->suivant; // On ref le suivant
		free(s2->name);
		free(s2); // On libere le tout
	}
	free(l->name);
	free(l);
}

Ligne *creer_ligne_avec_fichier(char *name, char *nom_fichier, int a, int b){
	/* Fonction qui cree une ligne portant le nom name
	 * On ouvre le fichier nom_fichier et on lit les noms de stations
	 * les nombres a et b servent à generer un nombre aleatoire de personnes sur le quai
	 */
	
	FILE* fichier = NULL;
	fichier = fopen(nom_fichier, "r");
	if(fichier == NULL){
		printf("Erreur lors de l'ouverture du fichier !");
		return NULL;
	}
	Ligne *l = creer_ligne(name);
	Station *s = NULL;
	char chaine[100] = ""; // On part du principe qu'il y a aura au maximun 100 caracteres
	while(fgets(chaine, 100, fichier) != NULL){
			s = creer_station(chaine, a, b);
			l = ajouter_station_ligne_en_tete(s, l);
		}
	fclose(fichier);
	
	return l;
}
// Fonctions de creation des trains et d'ajout aux lignes

