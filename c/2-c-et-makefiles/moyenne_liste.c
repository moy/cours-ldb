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

	/* ... */

	fprintf(stdout, "La moyenne de la liste est : %f\n", mean);

	return 0;
}

