#ifndef CR_TABLE_HACHAGE_H
#define CR_TABLE_HACHAGE_H

/* Le type table_hachage_t est prive */
typedef struct _table_hachage_t table_hachage_t;

/*
 * Renvoie un pointeur vers une nouvelle table.
 * On lui passe comme argument :
 *   - la taille du tableau (i.e. le nombre de cles differentes)
 *   - la fonction de comparaison des elements
 *   - la fonction de hachage
 *   - la fonction d'affichage d'un element
 */
extern table_hachage_t *new_table_hachage(unsigned,
					  int (*)(void *, void *),
					  unsigned (*)(void *),
					  void (*)(void *));

extern void inserer_table_hachage(table_hachage_t *, void *);

/* Affiche le contenu de la table */
extern void afficher_table_hachage(table_hachage_t *);

/* Renvoie != 0 ssi la table est vide et 0 sinon */
extern unsigned est_vide_table_hachage(table_hachage_t *);

/* Insere un element dans la table */
extern void inserer_table_hachage(table_hachage_t *, void *);

/* Retire un element de la table (sans effet s'il est absent) */
extern void supprimer_table_hachage(table_hachage_t *, void *);

/* Detruit la liste en desallouant tous ses elements */
extern void detruire_table_hachage(table_hachage_t *);

#endif // CR_TABLE_HACHAGE_H
