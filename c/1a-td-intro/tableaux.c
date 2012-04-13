#include <time.h>
#include <stdio.h>
#include <stdlib.h>

// initialise un tableau d'entier avec des chiffres tires aleatoirement
//   entre 0 et 9
void init_tab(int tab[], unsigned taille)
{
    for (unsigned i = 0; i < taille; i++) 
        tab[i] = rand() % 10; // % est l'operateur modulo
}

// affiche un tableau d'entiers signes
void affiche_tab(int tab[], unsigned taille)
{
    for (unsigned i = 0; i < taille; i++)
        printf("%i ", tab[i]);
    printf("\n");
}

// tri un tableau d'entiers par ordre croissant selon l'algorithme du tri
//   a bulles
void tri_bulle(int tab[], unsigned taille)
{
    for (unsigned sup = taille; sup > 1; sup--)
        for (unsigned i = 0; i < sup - 1; i++)
            if (tab[i] > tab[i + 1]) {
                int t = tab[i]; tab[i] = tab[i + 1]; tab[i + 1] = t;
            }
}

// renvoie l'indice du plus petit element dans le tableau
// la recherche s'effectue dans tab[0..sup[
unsigned indice_min(int tab[], unsigned sup)
{
    unsigned ix_min, i;
    // piege : si on declare unsigned ix_min ci-dessus et qu'on ecrit
    //   unsigned i = 1, ix_min = 0 ci-dessous, on redefini une variable
    //   ix_min qui cache celle ci-dessus, d'ou incoherence des valeurs,
    //   et tout ca sans Warning bien sur
    for (i = 1, ix_min = 0; i < sup; i++)
        if (tab[i] < tab[ix_min]) {
            ix_min = i;
        }
    return ix_min;
}

// tri un tableau d'entiers par ordre decroissant selon l'algorithme du
//   tri par selection du minimum
void tri_min(int tab[], unsigned taille)
{
    for (unsigned sup = taille; sup > 0; sup--) {
        unsigned ix_min = indice_min(tab, sup);
        if (ix_min != sup - 1) {
            int t = tab[ix_min];
            tab[ix_min] = tab[sup - 1];
            tab[sup - 1] = t;
        }
    }
}

int main(void)
{
    // On initialise le generateur de nombres aleatoire
    srand(time(NULL));

    unsigned taille;
    printf("Entrer la taille du tableau : ");
    scanf("%u", &taille);

    int tab[taille];
    init_tab(tab, taille);
    affiche_tab(tab, taille);

    tri_bulle(tab, taille);
    affiche_tab(tab, taille);

    tri_min(tab, taille);
    affiche_tab(tab, taille);

    return 0;
}

