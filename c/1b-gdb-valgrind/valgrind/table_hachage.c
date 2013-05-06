#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "table_hachage.h"

typedef struct _cellule {
	void *val;
	struct _cellule *suiv;
} cellule_t;

struct _table_hachage_t {
	unsigned nbr;
	unsigned largeur;
	int (*egal) (void *, void *);
	unsigned (*hashcode) (void *);
	void (*afficher) (void *);
	cellule_t **table;
};

table_hachage_t *new_table_hachage(unsigned largeur,
				   int (*egal) (void *, void *),
				   unsigned (*hashcode) (void *),
				   void (*afficher) (void *))
{
	table_hachage_t *t = malloc(sizeof(table_hachage_t));
	assert(t != NULL);
	t->largeur = largeur;
	t->nbr = 0;
	t->egal = egal;
	t->hashcode = hashcode;
	t->afficher = afficher;
	t->table = malloc(largeur * sizeof(cellule_t *));
	assert(t->table != NULL);
	return t;
}

void afficher_table_hachage(table_hachage_t * t)
{
	unsigned i;
	cellule_t *c;
	printf("La table contient %u elements :\n", t->nbr);
	for (i = 0; i < t->largeur; i++) {
		printf("[%u] -> ", i);
		for (c = t->table[i]; c != NULL; c = c->suiv) {
			t->afficher(c->val);
			printf(" -> ");
		}
		printf("fin\n");
	}
	printf("\n");
}

unsigned est_vide_table_hachage(table_hachage_t * t)
{
	return t->nbr == 0;
}

void inserer_table_hachage(table_hachage_t * t, void *val)
{
	unsigned i;
	cellule_t *tmp;
	t->nbr++;
	i = t->hashcode(val) % t->largeur;
	tmp = t->table[i];
	t->table[i] = malloc(sizeof(cellule_t));
	assert(t->table[i] != NULL);
	/*
	 * Attention : on recopie le POINTEUR, pas le CONTENU de val,
	 * il faut donc que l'objet val survive plus longtemps que la
	 * table
	 */
	t->table[i]->val = val;
	t->table[i]->suiv = tmp;
}

void supprimer_table_hachage(table_hachage_t * t, void *val)
{
	unsigned i;
	cellule_t *prec, *tmp, sent;
	i = t->hashcode(val) % t->largeur;
	sent.suiv = t->table[i];
	for (prec = &sent;
	     (prec != NULL) && !t->egal(prec->suiv->val, val);
	     prec = prec->suiv) {};
	if (prec->suiv != NULL) {
		t->nbr--;
		tmp = prec->suiv;
		if (prec == &sent)
			t->table[i] = prec->suiv->suiv;
		else
			prec->suiv = prec->suiv->suiv;
		free(tmp);
	}
}

void detruire_table_hachage(table_hachage_t * t)
{
	unsigned i;
	cellule_t *tmp;
	for (i = 0; i < t->nbr; i++)
		while (t->table[i] != NULL) {
			tmp = t->table[i];
			t->table[i] = t->table[i]->suiv;
			free(tmp);
		}
	free(t);
}
