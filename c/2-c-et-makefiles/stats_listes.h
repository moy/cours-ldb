/*
 * Spécification : stats_listes.h
 * Auteurs       : Enseignants du projet C Ensimag
 * Permet de gérer des statistiques sur une liste d'entiers
 * de données fourni par l'utilisateur
 */

#ifndef STATS_LISTES_H
#define STATS_LISTES_H

#include "liste.h"

/*
 * Accès au minimum de la liste
 * Renvoie le minimum
 * Précondition : la liste est non-vide
 */
extern int stat_listes_min(const liste* const l);

/*
 * Accès au maximum de la liste
 * Renvoie le maximum
 * Précondition : la liste est non-vide
 */
extern int stat_listes_max(const liste* const l);

/*
 * Accès à la moyenne de la liste
 * Renvoie la moyenne
 * Précondition : la liste est non-vide
 */
extern float stat_listes_moyenne(const liste* const l);

#endif /* STATS_LISTES_H */
