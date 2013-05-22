#include <stdio.h>
#include <stdlib.h>


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
	/* ... */
	affiche(tab, TAILLE);
	return 0;
}
