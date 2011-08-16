#include <stdio.h>

int cowboy_val[] = {0x44332211};

int est_little_endian() {
	/* ... */
}

int est_big_endian() {
	/* ... */
}

/*
* C'est un peu articiel mais c'est pour jouer avec des pointeurs.
* Principe :
*  s->    <-d
* +--+--+--+--+----
* |  |  |  |  | ...
* +--+--+--+--+----
* <-- src[i] ->
*/
void echange(int src[]) {
	/* ... */
}

void affiche(int tab[]) {
	int i;
	for (i = 0; tab[i]; i ++) {
		printf("0x%X ", tab[i]);
	}
	printf("\n");
}

int main() {
	int src[] = {0x00C0FFEE, 0xDECAFF00, 0xDEADBEEF,
		     0xEFFACEEE, 0xBEBAADAB, 0xEFBEADDE, 0};
	printf("Little-endian : %s.\n",
	       est_little_endian() ? "oui" : "non");
	printf("Big-endian : %s.\n",
	       est_big_endian() ? "oui" : "non");
	affiche(src);
	echange(src);
	affiche(src);
	return 0;
}
