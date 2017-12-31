#include <stdio.h>
#include <stdlib.h>

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

int length_file(char *name_file){
	// Renvoie le nombre de chaines dans le fichier
	
	FILE* file = NULL;
	file = fopen(name_file, "r");
	if(file == NULL){
		fprintf(stderr, "File Error !");
		return 0;
	}
	
	int i = 0;
	char chaine[100] = "";
	while(fgets(chaine, 100, file) != NULL){
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
	char chaine[100] = "";
	while(fgets(chaine, 100, file) != NULL){
		copy_chaine = creer_name(chaine);
		tableau_chaines[i] = copy_chaine;
		i++;
	}
	fclose(file);
	tableau_chaines[i] = NULL;
	
	return tableau_chaines;
}

void afficher_tableau_chaine(char **tableau_chaines){
	int i = 0;
	while(tableau_chaines[i] != NULL){
		printf("%s\n", tableau_chaines[i]);
		i++;
	}
}

void liberer_tableau_chaine(char **tableau_chaines){
	int i = 0;
	while(tableau_chaines[i] != NULL){
		free(tableau_chaines[i]);
		i++;
	}
	free(tableau_chaines);
}
