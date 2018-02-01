#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

char *create_name(char *name){
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

char **array_str_file(char *name_file){
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
		copy_chaine = create_name(chaine);
		tableau_chaines[i] = copy_chaine;
		i++;
	}
	fclose(file);
	tableau_chaines[i] = NULL; // le dernier element est NULL, pour signaler la fin
	
	return tableau_chaines;
}

void print_array_str(char **tableau_chaines){
	int i = 0;
	while(tableau_chaines[i] != NULL){
		printf("%s\n", tableau_chaines[i]);
		i++;
	}
}

void free_array_str_file(char **tableau_chaine){
	int i = 0 ;
	while(tableau_chaine[i] != NULL){
		free(tableau_chaine[i]);
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
