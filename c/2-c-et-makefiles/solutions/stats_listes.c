/*
 * Spécification : stats_listes.c
 * Auteurs       : Enseignants du projet C Ensimag
 * Implementation du module permettant de gérer des statistiques
 * sur une liste d'entiers fourni par l'utilisateur
 */

#include <stdio.h>
#include <stdlib.h>
#include "stats_listes.h"
#include "stats.h"

/* START CUT */
static void entrer_valeur_ptr(int * v) {
	stat_entrer_valeur(*v);
}
/* END CUT */

int stat_listes_min(const liste* const l)
{
	/* START CUT */
	int resultat;
	stat_init();
	liste_parcours(entrer_valeur_ptr, l);
        resultat = stat_min();
	stat_end();
	return resultat;
	/* END CUT */
	/* UNCOMMENT abort(); // TODO */
}

int stat_listes_max(const liste* const l)
{
	/* START CUT */
	int resultat;
	stat_init();
	liste_parcours(entrer_valeur_ptr, l);
	resultat = stat_max();
	stat_end();
	return resultat;
	/* END CUT */
	/* UNCOMMENT abort(); // TODO */
}

float stat_listes_moyenne(const liste* const l)
{
	/* START CUT */
	float resultat;
	stat_init();
	liste_parcours(entrer_valeur_ptr, l);
	resultat = stat_moyenne();
	stat_end();
	return resultat;
	/* END CUT */
	/* UNCOMMENT abort(); // TODO */
}
