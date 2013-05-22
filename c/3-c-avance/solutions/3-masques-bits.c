#include <stdio.h>

void affiche(unsigned char x) {
	/* START CUT */
	int i;
	for (i = 0; i < 8; i ++) {
		printf("%u", (x >> (7 - i)) & 1);
	}
	printf("\n");
	/* END CUT */
	/* ... */
}

unsigned char echange(unsigned char s) {
	/* START CUT */
	unsigned d, i;
	for (i = d = 0; i < 8; i ++) {
		d |=  ((s >> (7 - i)) & 1) << i;
	}
	return d;
	/* END CUT */
	/* ... */
}

int main() {
	int a;
	affiche(0xAA);
	affiche(echange(0xAA));
	affiche(0x55);
	affiche(echange(0x55));
	affiche(0x00);
	affiche(echange(0x00));
	a = 5;
	/* 05 FFFFFFFA 05 */
	printf("%02X %02X %02X\n", a, ~a, ~~a);
	/* 05 00 01 */
	printf("%02X %02X %02X\n", a, !a, !!a);
	return 0;
}
