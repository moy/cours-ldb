#include <stdio.h>
#include <string.h>

const int TAILLE = 16;

int main(int argc, char* argv[]) {
	/* START CUT */
	int i, taille;
	char chaine[TAILLE];
	strcpy(chaine, argv[0]);
	taille = strlen(argv[0]) + 1;
	for (i = 1; i < argc; i ++) {
		taille += strlen(argv[i]);
		if (taille > TAILLE) {
			fprintf(stderr, "Erreur : le tableau est plein\n");
			break;
		} else {
			strcat(chaine, argv[i]);
		}
	}
	printf("%s\n", chaine);
	/* END CUT */
	/* ... */
	return 0;
}
