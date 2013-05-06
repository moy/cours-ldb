#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    printf("Nom du programme : ");
    for (int i = 0; argv[0][i] != '\0'; i++)
        printf("%c", argv[0][i]);
    printf("\n");

    for (int i = 1; i < argc; i++)
        printf("  argument %i : %s\n", i, argv[i]);

    unsigned taille = strlen(argv[0]) + 2; // on ajoute " " et \0
    for (int i = 1; i < argc; i++)
        taille += strlen(argv[i]) + 1; // on ajoute " " a la fin

    char chaine[taille];
    strcpy(chaine, argv[0]);
    for (int i = 1; ; i++) {
        strcat(chaine, " ");
        if (i == argc) break;
        strcat(chaine, argv[i]);
    }

    printf("La ligne de commande est %s\n", chaine);

    char prog[strlen(argv[0]) + 1];
    strcpy(prog, argv[0]);

    prog[7] = 'X';

    if (strcmp(prog, argv[0]))
        printf("Les chaines \"%s\" et \"%s\" sont differentes\n", prog, argv[0]);

    return 0;
}
