#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structures.h"
#include <time.h>
#define MAX_FILE 300

int length_str(char *str){
	int i =0;
	while(str[i] != '\0' && str[i] != '\n'){
		i++;
	}
	return i;
}

int random_a_b(int a, int b){
	// Renvoie un nombre entra et b exclu
	return rand()%(b-a) + a;
}

char *creer_name(char *name){
	// On calcule d'abord la longueur de la chaine (sans les retour a la ligne)
	int i = length_str(name);
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

char *create_str_add(char *str1, char *str2, char add){
	/* Le parametre permet eventuellement d'ajouter un caractere entre str1 et str2
	 * Si on ne veut rien mettre entre les deux, mettre '\0'
	 */
	int length_str1 = length_str(str1);
	int length_str2 = length_str(str2);
	int total_length = length_str1 + length_str2;
	if(add != '\0'){
		total_length++;
	}
	char *str_final = NULL;
	str_final = (char *)(malloc(sizeof(char) * (total_length + 1)));
	
	int n = 0;
	int i;
	for(i = 0; i < length_str1; i++){
		str_final[n] = str1[i];
		n++;
	}
	
	if(add != '\0'){
		str_final[n] = add;
		n++;
	}
	
	for(i = 0; i < length_str2; i++){
		str_final[n] = str2[i];
		n++;
	}
	
	str_final[n] = '\0';
	return str_final;
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
		return NULL;
	}
	
	int i1,i2,i3,i4; // Pour les autre entiers
	char chaine1[MAX_FILE] = "";
	char chaine2[MAX_FILE] = "";

	// On recupere
	fgets(chaine1, MAX_FILE, file);
	fgets(chaine2, MAX_FILE, file);
	fscanf(file, "%d %d %d %d", &i1, &i2, &i3, &i4);
	
	fclose(file);
	
	// On cree en placant les bonnes informations
	carac_poisson *ca = NULL;
	ca = allouer_carac_poisson(chaine1, chaine2, i1, i2, i3, i4);
	//liberer_name(copy1);
	//liberer_name(copy2);
	
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
	if(tab == NULL){
		return;
	}
	
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
	if(p != NULL){
		printf("%s : %d de taille, valeur %d et resistance %d. Gout : %s\n", 
			p->name, p->taille, p->valeur, p->resistance, p->gout);
	}
}

void free_poisson(poisson *p){
	if(p != NULL){
		liberer_name(p->name);
		liberer_name(p->gout);
		free(p);
	}
}

poisson *allouer_poisson_file(char *name, char *gout, int taille, int valeur, int resistance){
	// Fonction appelle dans le cas ou on connait tout du poisson (souvent la sauvegarde)
	poisson *p = NULL;
	p = (poisson *)(malloc(sizeof(poisson)));
	if(p == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	p->name = creer_name(name);
	p->gout = creer_name(gout);
	p->taille = taille,
	p->valeur = valeur;
	p->resistance = resistance;
	
	return p;
}

// L'inventaire
liste_poisson *allouer_liste_poisson(poisson *p){
	liste_poisson *l = NULL;
	l = (liste_poisson *)(malloc(sizeof(liste_poisson)));
	if(l == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	l->fish = p;
	l->suivant = NULL;
	
	return l;
}

void free_liste_poisson(liste_poisson *l){
	liste_poisson *copy;
	while(l != NULL){
		copy = l;
		l = l->suivant;
		free_poisson(copy->fish);
		free(copy);
	}
}

liste_poisson *add_poisson_liste(liste_poisson *l, poisson *p){
	liste_poisson *add = allouer_liste_poisson(p);
	add->suivant = l;
	return add;
}

void afficher_liste_poisson(liste_poisson *l){
	int i = 0;
	liste_poisson *copy = l;
	while(copy != NULL){
		printf("%d : ", i);
		afficher_poisson(copy->fish);
		copy = copy->suivant;
		i++;
	}
}

liste_poisson *remove_element_liste_poisson(liste_poisson *l, char *name, poisson **p){
	// passer &p lors de l'appel de la fonction
	liste_poisson *copy1 = l;
	liste_poisson *copy2 = NULL;
	
	while(copy1 != NULL){
		if(strcmp(name, copy1->fish->name) == 0){
			if(copy2 == NULL){
				// premier element de la liste correspont
				l = l->suivant;
			}
			else {
				copy2->suivant = copy1->suivant;
			}
			*p = copy1->fish;
			free(copy1); // On libere cette partie de liste (le poisson est renvoye par adresse sans etre free_malloc)
			return l; 
		}
		copy2 = copy1;
		copy1 = copy1->suivant;
	}
	
	*p = NULL; // Afin de s'assurer qu'il n'a rien trouve selon le name
	return l;
}

char **allouer_names_fish(carac_poisson **ref){
	int i = 0;
	while(ref[i] != NULL){
		i++;
	}
	
	char **names = NULL;
	names = (char **)(malloc(sizeof(char *) * (i + 1)));
	if(names == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	int j = 0;
	while(ref[j] != NULL){
		names[j] = creer_name(ref[j]->name);
		j++;
	}
	names[j] = NULL;
	
	return names;
}

void free_names_fish(char **names_fish){
	
	if(names_fish == NULL){
		return;
	}
	
	int i =0;
	while(names_fish[i] != NULL){
		liberer_name(names_fish[i]);
		i++;
	}
	free(names_fish);
}

poisson **allouer_stock_poisson(int taille){
	poisson **stock = NULL;
	stock = (poisson **)(malloc(sizeof(poisson *) * (taille)));
	if(stock == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	// Il n'y a pas de poissons initialement
	int i;
	for(i = 0; i < taille; i++){
		stock[i] = NULL;
	}
	
	return stock;
}

void free_stock_poisson(poisson **stock, int taille){
	int i;
	for(i = 0; i < taille; i++){
		if(stock[i] != NULL){
			free_poisson(stock[i]);
		}
	}
	free(stock);
}

bassin *allouer_bassin(int taille, char *ref){
	bassin *b = NULL;
	b = (bassin *)(malloc(sizeof(bassin)));
	if(b == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	b->taille = taille;
	b->stock = allouer_stock_poisson(taille);
	b->reference = allouer_ref_carac_poisson(ref);
	b->names_fish = allouer_names_fish(b->reference);
	
	return b;
}

void free_bassin(bassin *b){
	free_stock_poisson(b->stock, b->taille);
	free_ref_carac_poisson(b->reference);
	free_names_fish(b->names_fish);
	free(b);
}

int indice_bassin_libre(bassin *b){
	int i;
	int length = b->taille;
	
	for(i = 0; i < length; i++){
		if(b->stock[i] == NULL){
			return i;
		}
	}
	
	return -1; // Aucune place libre
}

char *random_name(char **names){
	int length = 0;
	while(names[length] != NULL){
		length++;
	}
	
	return names[random_a_b(0, length)];
}

void create_poisson_bassin(bassin *b){
	int indice = indice_bassin_libre(b);
	if(indice == -1){
		return;
	}
	poisson *p = NULL;
	p = allouer_poisson(random_name(b->names_fish), b->reference);
	b->stock[indice] = p;
	
}

int compter_poisson_bassin(bassin *b){
	int n = 0;
	int i;
	int length = b->taille;
	
	for(i = 0; i < length; i++){
		if(b->stock[i] != NULL){
			n++;
		}
	}
	return n;
}

void afficher_bassin(bassin *b){
	printf("Poissons presents dans le bassin :\n --- \n");
	int i;
	int length = b->taille;
	if(compter_poisson_bassin(b) == 0){
		printf("Vide !\n --- \n");
		return;
	}
	
	for(i=0; i < length; i++){
		afficher_poisson(b->stock[i]);
	}
	
	printf(" --- \n");
}

// Le pecheur et ses actions
pecheur *allouer_pecheur(char *name, int energie, int argent){
	pecheur *p = NULL;
	p = (pecheur *)(malloc(sizeof(pecheur)));
	if(p == NULL){
		printf("Erreur d'allocation de memoire !");
		return NULL;
	}
	
	p->name = creer_name(name);
	p->energie_max = energie;
	p->l = NULL; // Aucun poisson initialement
	p->energie = p->energie_max;
	p->argent = argent;
}

void free_pecheur(pecheur *p){
	liberer_name(p->name);
	free_liste_poisson(p->l);
	free(p);
}

void add_poisson_pecheur(pecheur *fisher, poisson *fish){
	fisher->l = add_poisson_liste(fisher->l, fish);
}

void remplir_poissons_pecheur(pecheur *p, char *name_file){
	FILE* file = NULL;
	file = fopen(name_file, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return;
	}
	
	char chaine[MAX_FILE] = "";
	char chaine2[MAX_FILE] = "";
	poisson *fish;
	int i1, i2, i3;

	while(fgets(chaine, MAX_FILE, file) != NULL){
		if(chaine[0] == '#'){
			fgets(chaine, MAX_FILE, file);
			fgets(chaine2, MAX_FILE, file);
			fscanf(file, "%d %d %d", &i1, &i2, &i3);
			fish = allouer_poisson_file(chaine, chaine2, i1, i2, i3);
			add_poisson_pecheur(p, fish);
		}
	}
	
	fclose(file);
}

pecheur *allouer_pecheur_file(char *save){
	char *chemin = create_str_add("files/saves/", save, '\0');
	char *info_pecheur = create_str_add(chemin, "pecheur.txt", '/');
	char *info_poissons = create_str_add(chemin, "poissons.txt", '/');
	liberer_name(chemin);
	
	FILE* file = NULL;
	file = fopen(info_pecheur, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		liberer_name(info_pecheur);
		liberer_name(info_poissons);
		return NULL;
	}
	
	char chaine[MAX_FILE] = ""; // Recuperation des chaines (puis transformation sans le '\n')
	int i1, i2;
	
	fgets(chaine, MAX_FILE, file);
	fscanf(file, "%d %d", &i1, &i2);
	pecheur *p = allouer_pecheur(chaine, i1, i2);
	fclose(file);
	liberer_name(info_pecheur);
	
	remplir_poissons_pecheur(p, info_poissons);
	liberer_name(info_poissons);
	
	return p;
}
int compter_poisson_pecheur(pecheur *p){
	int n = 0;
	liste_poisson *liste = p->l;
	 
	while(liste){
		n++;
		liste = liste->suivant;
	}
	
	return n;
}

void afficher_pecheur(pecheur *p){
	printf("Le pecheur %s a une energie de (%d/%d) et a %d argent.\n", p->name, p->energie, p->energie_max, p->argent);
	printf("Voici les poissons en sa possession :\n");
	if(compter_poisson_pecheur(p) == 0){
		printf("Aucun :(\n");
		return;
	}
	afficher_liste_poisson(p->l);
}

poisson *bassin_poisson(bassin *b){
	int i;
	int length = b->taille;
	poisson *p;
	
	for(i = 0; i < length; i++){
		if(b->stock[i] != NULL){
			p = b->stock[i];
			b->stock[i] = NULL; // Le poisson est retire du bassin (que la peche soit reussi ou non)
			return p; // On le renvoie
		}
	}
	return NULL; // Aucun poisson trouve !
}

void pecher_poisson_bassin(pecheur *p, bassin *b){
	if(p->energie == 0){
		return;
	}
	p->energie = p->energie -1;
	
	poisson *p_premier = bassin_poisson(b);
	
	if(p_premier == NULL){
		// Pas de poisson :( (ou une erreur ?)
		return;
	}
	
	if(random_a_b(0, p_premier->resistance) == 0){
		printf("Poisson peche !\n");
		add_poisson_pecheur(p, p_premier);
	}
}

void vendre_poisson(pecheur *p, char *name_poisson){
	// Le pecheur vends un poisson portant le nom
	poisson *fish;
	p->l = remove_element_liste_poisson(p->l, name_poisson, &fish);
	
	// fish peut etre NULL si aucun poisson n'a ce name
	if(fish != NULL){
		p->argent = p->argent + (fish->taille * fish->valeur);
		free_poisson(fish);
	}
}

// Sauvegarde
int save_pecheur(pecheur *p, char *file_name){
	// Renvoie 1 si la sauvegarde a reussi, 0 sinon
	FILE *file = NULL;
	file = fopen(file_name, "w+");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	fprintf(file, "%s\n%d\n%d\n", p->name, p->energie_max, p->argent);
	
	fclose(file);
	return 1;
}

int save_poissons(pecheur *p, char *file_name){
	// Renvoie 1 si la sauvegarde a reussi, 0 sinon
	FILE *file = NULL;
	file = fopen(file_name, "w+");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	// On parcourt la liste entierement
	liste_poisson *copy = p->l;
	while(copy != NULL){
		fprintf(file, "#\n%s\n%s\n%d\n%d\n%d\n", copy->fish->name,copy->fish->gout,
			copy->fish->taille,copy->fish->valeur,copy->fish->resistance);
		copy = copy->suivant;
	}
	
	fclose(file);
	return 1;
}

void save_game(pecheur *p, char *save){
	// Save est le nom du dossier de sauvegarde
	char *chemin = create_str_add("files/saves/", save, '\0');
	char *info_pecheur = create_str_add(chemin, "pecheur.txt", '/');
	char *info_poissons = create_str_add(chemin, "poissons.txt", '/');
	liberer_name(chemin);
	
	if(save_pecheur(p,info_pecheur) == 0){
		printf("Erreur survenue lors de la sauvegarde !");
		return;
	}
	liberer_name(info_pecheur);
	
	if(save_poissons(p,info_poissons) == 0){
		printf("Erreur survenue lors de la sauvegarde !");
		return;
	}
	liberer_name(info_poissons);
	
	printf("Sauvegarde reussi !\n");
}

void new_game(char *save){
	// Save est le nom du dossier de sauvegarde
	char *chemin = create_str_add("files/saves", save, '/');
	printf("%s\n", chemin);
	char *poissons = create_str_add(chemin, "poissons.txt", '/');
	char *fisher = create_str_add(chemin, "pecheur.txt", '/');
	printf("%s\n%s\n", fisher, poissons);
	liberer_name(chemin);
	
	// Faire une fonction d'appel pour demander un nom
	pecheur *p = allouer_pecheur("player", 10, 0);
	
	FILE *file = NULL;
	file = fopen(fisher, "w+");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return;
	}
	
	fclose(file);
	liberer_name(fisher);
	
	file = fopen(poissons, "w+");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return;
	}

	fclose(file);
	liberer_name(poissons);
	
	save_game(p, save);
	free_pecheur(p);
}
