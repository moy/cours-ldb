#include <stdio.h>

int cowboy_val[] = {0x44332211};

int est_little_endian() {
	/* START CUT */
	return *((char *) cowboy_val) == 0x11;
	/* END CUT */
	/* ... */
}

int est_big_endian() {
	/* START CUT */
	return *((char *) cowboy_val) == 0x44;
	/* END CUT */
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
	/* START CUT */
	char *s, *d, t;
	int i;
	for (i = 0; src[i]; i ++) {
		s = (char *) (src + i);
		d = s + 3;
		/*
	         * *s++ et *d-- : un bon exemple de code illisible, mais
	         * il faut l'avoir vu au moins une fois dans sa vie !
		 *   *s++ = *d <=> *(s++) = *d <=> *s = *d ; s ++
		 */
		t = *s; *s++ = *d; *d-- = t;
		t = *s; *s = *d; *d = t;
		/*
		 * Variante un chouilla plus lisible :
		 * t = *s;     *s = *(s+3);     *(s+3) = t;
		 * t = *(s+1); *(s+1) = *(s+2); *(s+2) = t;
		 */
	}
	/* END CUT */
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
