#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef struct _cellule {
	int val;
	struct _cellule* suiv;
} cellule;

typedef struct {
	cellule* tete;
	cellule* queue;
} liste;

/* #x, pour le préprocesseur = x avec des guillemets autour. */
#define STRINGIFY(x) #x

/*
 * Note: le abort() ici est très brutal.
 * Si on utilise ce module en temps que bibliothèque pour une grosse
 * application, le "abort()" arrête l'ensemble de l'application sans
 * possibilité de rattrapage d'erreur (un peu comme "exit(1)").
 * Si on avait des exceptions, ça serait mieux ... mais en C,
 * c'est compliqué de faire plus propre.
 */
#define VERIF_NULL(ptr)							\
	if (! ptr) {							\
		fprintf(stderr, "Erreur [%s:%u] : pointeur nul \"%s\"\n", \
			__FILE__, __LINE__, STRINGIFY(ptr)); abort(); }

liste* init_liste() {
	liste* l;
	l = (liste*) malloc(sizeof(liste));
	VERIF_NULL(l);
	l->tete = NULL;
	l->queue = NULL;
	return l;
}

int est_vide(const liste* const l) {
	VERIF_NULL(l);
	assert(l->tete || !(l->tete));
	return !(l->tete);
}

void affiche(const liste* const l) {
	cellule* ptr;
	VERIF_NULL(l);
	for (ptr = l->tete; ptr ; ptr = ptr->suiv) {
		printf("%d -> ", ptr->val);
	}
	printf("FIN\n");
}

void insere_tete(int v, liste* const l) {
	cellule* new;
	VERIF_NULL(l);
	new = (cellule*) malloc(sizeof(cellule));
	VERIF_NULL(new);
	new->val = v;
	new->suiv = l->tete;
	l->tete = new;
	if (est_vide(l)) {
		l->queue = new;
	}
}

void insere_queue(int v, liste* const l) {
	cellule *new;
	VERIF_NULL(l);
	new = (cellule*) malloc(sizeof(cellule));
	VERIF_NULL(new);
	new->val = v;
	new->suiv = NULL;
	if (est_vide(l)) {
		l->tete = new;
	} else {
		l->queue->suiv = new;
	}
	l->queue = new;
}

int recherche(int v, liste* const l) {
	cellule* cour;
	VERIF_NULL(l);
	for (cour = l->tete; cour && (cour->val != v); cour = cour->suiv);
	return (int) cour;
}

void parcours(void (*fct)(int*),
	      const liste* const l) {
	cellule *cour;
	VERIF_NULL(l);
	for (cour = l->tete; cour; cour = cour->suiv) {
		fct(&(cour->val));
	}
}

void supprime_element(int v,
		      liste* const l) {
	cellule sent, *prec, *tmp;
	VERIF_NULL(l);
	sent.suiv = l->tete;
	for (prec = &sent;
	     prec->suiv && (prec->suiv->val != v);
	     prec = prec->suiv);
	if (prec->suiv) {
		if (prec->suiv == l->tete) {
			l->tete = l->tete->suiv;
		} else if (prec->suiv == l->queue) {
			l->queue = prec;
		}
		tmp = prec->suiv;
		prec->suiv = tmp->suiv;
		free(tmp);
	}
}
