/* 
 * Implementation: stats.c
 * Auteurs       : Enseignants du projet C Ensimag
 * Implementation du module permettant de gérer des statistiques
 * sur un ensemble de données fourni par l'utilisateur
 */

#include <stdio.h>
#include <stdlib.h>
/* Pour INT_MAX et INT_MIN */
#include <limits.h>
#include "stats.h"

/* START CUT */
static int    nb_valeurs;  /*Nombre de valeurs entrées*/
static int    min;        /*le minimum de l'ensemble*/
static int    max;        /*le maximum de l'ensemble*/
static float  total;      /*le total de l'ensemble*/
/* END CUT */

/* START CUT */
/*
 * Initialisation des variables statistiques
 */
/* END CUT */
void stat_init()
{
	/* START CUT */
	min      = INT_MAX;
	max      = INT_MIN;
	total     = 0;
        nb_valeurs = 0;
	/* END CUT */
	/* ... */
}

/* START CUT */
/*
 * Destruction de l'ensemble
 * Rien dans l'implémentation actuelle du paquet, mais si un jour on
 * veut faire des analyses plus fines, on risque
 * d'avoir à allouer de la mémoire, et il faudrait la désallouer ici.
 *
 * Une fonction vide comme celle-ci permet de s'assurer de la
 * compatibilité avec les versions futures pour les gens qui ont
 * respecté l'API.
 */
/* END CUT */
void stat_end()
{
	/* START CUT */

	/* END CUT */
	/* ... */
}

/* START CUT */
/* Remplissage de l'ensemble à traiter
 * Une valeur value est ajoutée à la fois
 */
/* END CUT */
void stat_entrer_valeur(int value)
{
	/* START CUT */
	if(value < min) min = value;
	if(value > max) max = value;
	total              += value;
	nb_valeurs++;
	/* END CUT */
}


/* START CUT */
/*
 * Accès au minimum de l'ensemble
 * Renvoie le minimum
 */
/* END CUT */
int stat_min()
{
	/* START CUT */
	return min;
	/* END CUT */
}

/* START CUT */
/*
 * Accès au maximum de l'ensemble
 * Renvoie le maximum
 */
/* END CUT */
int stat_max()
{
	/* START CUT */
	return max;
	/* END CUT */
}

/* START CUT */
/* 
 * Accès à la moyenne de l'ensemble
 * Renvoie la moyenne
 */
/* END CUT */
float stat_moyenne()
{
	/* START CUT */
	return total/nb_valeurs;
	/* END CUT */
}
