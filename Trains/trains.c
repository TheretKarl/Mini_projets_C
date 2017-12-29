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
	s->type = random_a_b(1,4); // Entre 1 et 4(exclu)
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
	if(s == NULL){
		printf("Ligne vide !\n");
		return;
	}
	while(s->suivant != NULL){
		if(s->nb_personnes == s->nb_max_personnes){
			printf("X-");
		}
		else {
			printf("O-");
		}
		s = s->suivant; // On passe au suivant
	}
	if(s->nb_personnes == s->nb_max_personnes){
		printf("X\n");
	}
	else {
		printf("O\n");
	}
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

void afficher_etat_ligne(Ligne *l){
	// On considere que la ligne a bien a ete initialise !
	printf("Voici la ligne %s :\n", l->name);
	afficher_ligne(l);
}
// Fonctions de creation des trains et d'ajout aux lignes

Wagon *creer_wagon(int place){
	Wagon *w = (Wagon *)(malloc(sizeof(Wagon)));
	if(w == NULL){
		printf("Erreur d'allocation !");
		return NULL;
	}
	w->nb_max_personnes = place;
	w->nb_personnes = 0;
	w->suivant = NULL;
	return w;
}

void ajouter_wagon_train(Train *t, Wagon *w){
	if(t->premier == NULL){
		// S'il y a aucun wagon
		t->premier = w;
		return;
	}
	Wagon *w2 = t->premier;
	while(w2->suivant){
		// On cherche la premiere place disponible
		w2 = w2->suivant;
	}
	w2->suivant = w; // On l'accroche a la suite
}

Train *creer_train(int place, int longueur){
	/* Cette fonction cree longeur de wagon
	 * avec n place a chaque wagon
	 * tires par un train devant 
	 * direction, ligne et actuelle non initialise ! (ajout_ligne)
	 */
	
	Train *t = (Train *)(malloc(sizeof(Train)));
	if(t == NULL){
		printf("Erreur d'allocation !");
		return NULL;
	}
	t->premier = NULL;
	
	Wagon *w = NULL;
	int n;
	for(n = 0; n < longueur; n++){
		w = creer_wagon(place);
		ajouter_wagon_train(t, w);
	}
	return t;
}

void mettre_train_en_ligne(Train *t, Ligne *l){
	t->ligne = l;
	if(random_a_b(0,2)){
		t->direction = 0; // Se deplace en direction de la "fin"
		t->actuelle = l->premier;
	}
	else {
		t->direction = 1;
		t->actuelle = l->dernier;
	}
}

void liberer_train(Train *t){
	Wagon *w = t->premier;
	Wagon *w2;
	free(t);
	while(w != NULL){
		w2 = w;
		w = w->suivant;
		free(w2);
	}
}

void afficher_etat_train(Train *t){
	Wagon *w = t->premier;
	if(w == NULL){
		printf(" Vide !\n");
		return;
	}
	printf("[T]");
	int cpt = 0; int cpt_max = 0; // Permet de savoir combien de gens sont la
	while(w != NULL){
		cpt_max = cpt_max + w->nb_max_personnes;
		cpt = cpt + w->nb_personnes;
		if(w->nb_personnes == w->nb_max_personnes){
			printf("-[WP]");
		}
		else if(w->nb_personnes == 0) {
			printf("-[WV]");
		}
		else {
			printf("-[WL]");
		}
		w = w->suivant;
	}
	printf("\nIl y a %d sur %d personnes.\n", cpt, cpt_max);
}

// Fonctions de deplacement de train et des passagers

int compter_wagon_libre(Wagon *w){
	// Renvoie la place libre dans le wagon
	return w->nb_max_personnes - w->nb_personnes;
}

int compter_train_libre(Train *t){
	// Renvoie la place libre dans le total de wagons
	Wagon *w = t->premier;
	int cpt = 0;
	if(w == NULL){
		return 0;
	}
	while(w != NULL){
		cpt = cpt + compter_wagon_libre(w);
		w = w->suivant;
	}
	return cpt;
}

void train_move(Train *t){
	if(t->actuelle == t->ligne->premier){
		// Est en debut de ligne
		t->direction = 0;
	}
	else if(t->actuelle == t->ligne->dernier){
		// else if au cas ou n'y a qu'un seul arret, Est en fin de ligne
		t->direction = 1;
	}
	if(t->direction == 0){
		// Va vers la fin
		t->actuelle = t->actuelle->suivant;
	}
	else {
		// Va vers le debut
		t->actuelle = t->actuelle->precedent;
	}
}

void train_deposer_passagers(Train *t){
	Wagon *w = t->premier;
	if(w == NULL){
		printf("Wagon Vide !");
		return;
	}
	// type, dans la station, definie le nombre de personnes qui descendent
	
	int temp = t->actuelle->type;
	while(w != NULL){
		w->nb_personnes = w->nb_personnes / temp ;
		w = w->suivant;
	}
}

void train_prendre_passagers(Train *t){
	Wagon *w = t->premier;
	if(w == NULL){
		printf("Wagon Vide !");
		return;
	}
	
	int reste = t->actuelle->nb_personnes; // Nombre de personne sur la station
	int temp;
	do{
		temp = compter_wagon_libre(w);
		if(temp > 0){
			if(reste <= temp){
				// S'il a moins ou tout juste assez de personnes sur le quai pour remplir le wagon
				w->nb_personnes = w->nb_personnes + reste;
				reste = 0;
			}
			else {
				// Il y a trop de gens pour le wagon
				w->nb_personnes = w->nb_max_personnes;
				reste = reste - temp;
			}
		}
		w = w->suivant; // On continue d'avancer dans le train
	}while(w != NULL && reste >= 0);
	t->actuelle->nb_personnes = reste;
}

void train_action(Train *t){
	train_deposer_passagers(t);
	train_prendre_passagers(t);
	train_move(t);
}

// Fonctions de remplissage des quais

void remplir_station(Station *s){
	s->nb_personnes = s->nb_personnes + (int)(s->nb_max_personnes * 0.2);
	if(s->nb_personnes > s->nb_max_personnes){
		s->nb_personnes = s->nb_max_personnes;
	}
}

void remplir_ligne(Ligne *l){
	Station *s = NULL;
	if(l->premier == NULL){
		printf("Un probleme est survenu sur la ligne : %s\n", l->name);
		return;
	}
	s = l->premier;
	while(s != NULL){
		remplir_station(s);
		s = s->suivant;
	}
}
