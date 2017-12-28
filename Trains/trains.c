#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structures.h"

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

Station *creer_station(char *name){
	Station *s = (Station*)(malloc(sizeof(Station)));
	if(s == NULL){
		printf("Une erreur est survenue lors de l'allocation !\n");
		return NULL;
	}
	s->type = random_a_b(0,4);
	s->name = creer_name(name);
	// Il y a initialement 0 personnes sur le quai
	return s;
}

Ligne ajouter_station_ligne_en_tete(Station *s, Ligne l){
	Station *s2 = l.premier; // On sauvegarde
	l.premier = s; // On place au debut
	l.premier->suivant = s2; // On fait reference au suivant
	if(s2 != NULL){
		s2->precedent = s;
	}
	if(l.dernier == NULL){
		l.dernier = s;
	}
	return l;
}	

Ligne ajouter_station_ligne_en_queue(Station *s, Ligne l){
	Station *s2 = l.dernier; // On sauvegarde
	l.dernier = s; // On le place a la fin
	s->precedent = s2; // On fait reference au precedent
	if(s2 != NULL){
		s2->suivant = s;
	}
	if(l.premier == NULL){
		l.premier = s;
	}
	return l;
}

void afficher_ligne(Ligne l){
	Station *s = l.premier; // On prends le premier arret
	afficher_name(l.name);
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

void liberer_ligne(Ligne l){
	// Ligne l n'est pas une structure allouee dynamiquement !
	Station *s1 = l.premier;
	Station *s2;
	while(s1 != NULL){
		s2 = s1; // On garde en memoire
		s1 = s1->suivant; // On ref le suivant
		free(s2); // On libere
	}
}
