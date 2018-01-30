#ifndef structures
#define structures

typedef struct _information{
	int energie; // L'energie contenu
	int cryptage; // Allant de 1 a 10
}information;

typedef struct _carry{
	unsigned int type; // type vaut un chiffre qu'un moteur utilise correctement ou non
	information *transport;
}carry;

typedef struct _module{
	int energie;
	int energie_max;
	carry *individu;
	int decryptage;
}module;

typedef struct _pont{
	
}pont;
#endif
