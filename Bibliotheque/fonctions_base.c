#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "prototypes.h"

int length_str(char *str){
  /* Return the length of the string, stops when encouter \0 or \n */
  int i=0;
  while(str[i] != '\0' && str[i] != '\n'){
    i++;
  }
  return i;
}

char *create_str(char *str){
  /* Return a new allocate string without any \n */
  int length = length_str(str);
  char *new_str = (char *)(malloc(sizeof(char) * (length + 1)));
  if(new_str == NULL){
    printf("Erreur lors de l'allocation de la chaine\n");
    exit(0);
  }

  int i;
  for(i = 0; i < length; i++){
    new_str[i] = str[i];
  }
  new_str[i] = '\0';
  return new_str;
}

int length_file(char *name_file, int max_size){
  /* Return the number of line in a file, 
     First parameters is the name of the file,
     Second parameters is the number of char authorized per line 
  rewind the file stream when finished to compt*/
  int i = 0;
  char *take = (char *)(malloc(sizeof(char) * max_size));
  if(take == NULL){
    printf("Erreur lors de l'allocation\n");
    exit(0);
  }

  FILE *file = fopen(name_file, "r");
  if(file == NULL){
    printf("Fichier %s introuvable\n", name_file);
    exit(0);
  }
  
  while(fgets(take, max_size, file)){
    i++;
  }

  fclose(file);
  free(take);
  return i;
}

char **array_str_file(char *name_file, int max_size){
  /* Return an array of string with each line of a file
     Last if set as NULL */
  int length = length_file(name_file, 300) + 1;
  char **array = (char **)(malloc(sizeof(char *) * (length + 1)));
  FILE *file = fopen(name_file, "r");
  if(file == NULL){
    printf("Fichier %s introuvable\n", name_file);
    exit(0);
  }
  char *take = (char *)(malloc(sizeof(char) * max_size));
  if(take == NULL){
    printf("Erreur lors de l'allocation\n");
    exit(0);
  }

  int i = 0;
  while(fgets(take, max_size, file)){
    array[i] = create_str(take);
    i++;
  }
  array[i] = NULL;

  return array;
}

void print_array_str(char **array){
  /* Print the array of string */
  int i = 0;
  while(array[i]){
    printf("%s\n", array[i]);
    i++;
  }
}

void free_array_str(char **array){
  /* Free the allocated memory from the array */
  int i = 0;
  while(array[i] != NULL){
    free(array[i]);
    i++;
  }
  free(array);
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


int check_int(char *integer){
  /* Check if the integer char is a real integer
     and return the number of character is this integer
     Return 0 if it wasn't an integer */
  int i = 0;
  while(integer[i] != '\0'){
    if(integer[i] < '0' || integer[i] > '9'){
      return 0;
    }
    i++;
  }
  return i;
}

int strint(char *integer, int *i){
  /* Transform the char integer to i parameter which is the adress of the int 
     Return 0 if there were an error, 1 else */
  int neg = 0;
  char *cpy = integer;
  if(integer[0] == '-'){
    neg = 1;
    cpy = integer + 1;
  }
  
  int length = check_int(cpy);
  if(!length){
    return 0;
  }
  int res = 0;
  int x,a;
  for(x = 0; x < length; x++){
    a = cpy[x] - '0';
    res = res + ((a) * pow_n(10, length - x - 1));
  }
  
  if(neg){
    *i = -res;
  }
  else {
    *i = res;
  }
  
  return 1;
}


str_int *allocate_str_int(char *str, int data){
  str_int *si = (str_int *)(malloc(sizeof(str_int)));
  if(si == NULL){
    printf("Erreur lors de l'allocation !\n");
    return NULL;
  }

  si->str = create_str(str);
  si->data = data;

  return si;
}

void free_str_int(str_int *si){
  free(si->str);
  free(si);
}
