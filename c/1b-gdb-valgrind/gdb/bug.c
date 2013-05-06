/*
 * Commencer par gdb-tutorial.c, ce fichier est un exercice plus
 * difficile.
 */
#include <stdio.h>

#define TAILLE 3

/*
 * Ce programme est une tentative (ratée) d'initialisation d'un
 * tableau a 0. En pratique, il ne fait pas ce qu'il faut du tout :
 * - le tableau est mal initialisé
 * - les variables var1 et var2 sont modifiées alors qu'on ne voulait
 * pas y toucher.
 *
 * Le but ici est d'utiliser gdb pour trouver l'erreur (on pourrait la
 * trouver facilement en lisant le code, mais ce n'est pas le but).
 */
int var1 = 101;
int tab[TAILLE] = {0, 1, 2};
int var2 = 102;
int i;
int main (void) {
	printf("var1=%d\n", var1);
	printf("var2=%d\n", var2);
	i = 0;
	while (i <= TAILLE) {
		i++;
		/*
		 * Essayez de poser un point d'arret sur la ligne
		 * suivante. A chaque tour de boucle, affichez la
		 * valeur de i.
		 */
		tab[i] = 42;
		/*
		 * On pourra utiliser les commandes gdb suivantes :
		 * p i
		 * p tab[i]
		 * p &(tab[i])
		 * p &var1
		 * p &var2
		 */
	}
	for (i = 0; i <= TAILLE; i++) {
		printf("tab[%d] = %d\n",i , tab[i]);
	}
	printf("var1=%d\n", var1);
	printf("var2=%d\n", var2);
	return 0;
}
