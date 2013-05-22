#include <stdio.h>

void affiche(unsigned char x) {
	/* ... */
}

unsigned char echange(unsigned char s) {
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
