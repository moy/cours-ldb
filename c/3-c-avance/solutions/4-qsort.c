#include <stdio.h>
#include <stdlib.h>

/* START CUT */
/*
 * comp(a, b) renvoie :
 *  - une valeur negative si *a < *b
 *  - zero si *a = *b
 *  - une valeur positive si *a > *b
 */
int comp(const int* const a,
	 const int* const b) {
	return *a - *b; /* Ne marche que si *a - *b
			   ne provoque pas d'overflow */
}
/* END CUT */

void affiche(int tab[],
	     unsigned taille) {
	unsigned i;
	printf("[");
	for (i = 0; i < taille; i ++) {
		printf("%u ", tab[i]);
	}
	printf("\b]\n");
}

void cree_tableau(int tab[],
		  unsigned taille) {
	unsigned i;
	for (i = 0; i < taille; i ++) {
		tab[i] = rand() % taille;
	}
}

const int TAILLE = 10;

int main() {
	int tab[TAILLE];
	printf("Test quicksort : \n");
	cree_tableau(tab, TAILLE);
	affiche(tab, TAILLE);
	/* START CUT */
	qsort(tab, TAILLE, sizeof(int),
	      (int(*) (const void *, const void*)) comp);
	/* END CUT */
	/* ... */
	affiche(tab, TAILLE);
	return 0;
}
