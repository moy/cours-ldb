#include <stdio.h>

void affiche_un() {
	printf("Il y a un argument (en comptant le nom du programme).\n");
}

void affiche_autre_chose() {
	printf("argc != 1 cette fois-ci.\n");
}

int main(int argc, char **argv) {
	void (*fonction_a_appeler)(void);
	if (argc == 1)
		fonction_a_appeler = affiche_un;
	else
		fonction_a_appeler = affiche_autre_chose;
	
	/* 
	 * fonction_a_appeler est un pointeur sur fonction, on peut
	 * l'appeler comme une fonction normale :
	 */
	fonction_a_appeler();

	return 0;
}
