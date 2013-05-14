/*
 * Spécification : stats.h
 * Auteurs       : Enseignants du projet C Ensimag
 * Permet de gérer des statistiques sur un ensemble
 * de données fourni par l'utilisateur
 */

#ifndef _STATS_H_
#define _STATS_H_


/*
 * Initialisation du module
 */
extern void stat_init();

/*
 * Destruction de l'ensemble
 */
extern void stat_end();

/*
 * Remplissage de l'ensemble à traiter
 */
extern void stat_entrer_valeur(int value);

/*
 * Accès au minimum de l'ensemble
 * Renvoie le minimum
 */
extern int stat_min();

/*
 * Accès au maximum de l'ensemble
 * Renvoie le maximum
 */
extern int stat_max();

/*
 * Accès à la moyenne de l'ensemble
 * Renvoie la moyenne
 * Précondition : il y a eu au moins un appel à stat_entrer_valeur
 */
extern float stat_moyenne();


#endif
