Protocole pour ajouter des trains et des lignes dans le main
Creer une ligne avec creer_ligne_avec_fichier("Name Line", "Name_file.txt", x, y);

Creer un train avec *creer_train(int place, int longueur)
L'ajouter sur la ligne qui correpondant

Puis une fois dans la boucle principale :
 
	printf("%d\n", i);
	afficher_etat_ligne(ligne_choisie);
	Pour les n trains qui sont sur la ligne :
		afficher_etat_train(Train_numero_n);
		
	remplir_ligne(ligne_choisie);
	Pour les n trains qui sont sur la ligne :
		train_action(Train_numero_n);
		
	usleep(500000);
	i++;

