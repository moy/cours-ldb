#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *chaine = malloc(7);
    strcpy(chaine, "azerty");
    printf("%s\n", chaine);
    free(chaine);
    // FAUX : on n'a pas le droit d'acceder a une zone liberee
    // l'effet est imprevisible :
    //   - sur telesun, ca n'affiche rien
    //   - sur ma machine, ca affiche "azerty"
    printf("%s\n", chaine);
    char *c = malloc(7);
    // FAUX : c n'a pas ete initialisee, mais en pratique malloc allouera
    //   vraisemblablement la meme zone que celle qui vient d'etre liberee
    //   => effet imprevisible
    printf("%s\n", c);

    const int taille = 5;
    int *tab = calloc(taille, sizeof(int));
    int *copie =  malloc(taille * sizeof(int));
    memcpy(copie, tab, taille * sizeof(int));
    for (int i = 0; i < taille; i++)
        printf("%i ", copie[i]);
    printf("\n");
    // il est inutile de liberer la memoire en fin de programme, ca sera
    //   fait automatiquement quand le programme se termine
    
    while (1) {
        int *boom = calloc(2 * 1000 * 1000 * 1000, sizeof(int));
        assert(boom != NULL);
    }

    return 0;
}

