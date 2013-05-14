/*
 * Spécification : moyenne_liste.c
 * Auteurs       : Enseignants du projet C Ensimag
 * Programme principal
 */

#include <stdio.h>
#include <stdlib.h>
#include "liste.h"
#include "stats_listes.h"

int main(int argc, char *argv[])
{
	int value;     /*récupération des valeurs*/
	
	liste *l;
	float mean;

	(void) argc;
	(void) argv;

	fprintf(stdout, "Veuillez saisir une liste d'entiers positifs\n");
	fprintf(stdout, "Sortie : -1\n");

	/* START CUT */
	/*Initialisation de la liste*/
	l = liste_init();

	scanf("%d", &value);
	if(value == -1){
		return 1;
	}
	while(value != -1){
		liste_insere_tete(value,l);
		scanf("%d", &value);
	}

	/*Affichage de la moyenne*/
	mean = stat_listes_moyenne(l);
	/* END CUT */
	/* ... */

	fprintf(stdout, "La moyenne de la liste est : %f\n", mean);

	return 0;
}

