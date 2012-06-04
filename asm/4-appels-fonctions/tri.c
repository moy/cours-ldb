#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

// affiche un tableau d'entiers signes de taille donnee
void afficher_tab(int tab[], unsigned taille)
{
    for (unsigned i = 0; i < taille; i++)
        printf("%i ", tab[i]);
    printf("\n");
}

void tri_nain(int tab[], unsigned taille);

// fonction de comparaison utilise par le tri
//   de reference
int comp_int(const void *a, const void *b)
{
        return *(int*)a - *(int*)b;
}

void test_tri(unsigned taille, int trace) {
    // tableau initial
    int *org =  malloc(taille * sizeof(int)); assert(org);
    // tableau trie avec le tri de reference
    // il servira a verifier que le tri fonctionne
    int *ref =  malloc(taille * sizeof(int)); assert(ref);
    // tableau a trier
    int *tab =  malloc(taille * sizeof(int)); assert(tab);
    // remplissage avec des valeurs aleatoires
    for (unsigned i = 0; i < taille; i++) {
        org[i] = (rand() % 19) - 9;
    }
    if (trace == 1) {
        printf("Tableau initial : "); afficher_tab(org, taille);
    }
    // tri de reference
    memcpy(ref, org, sizeof(int) * taille);
    clock_t debut = clock();
    qsort(ref, taille, sizeof(int), comp_int);
    clock_t fin = clock();
    printf("Tri de reference effectue en %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    // tri du nain
    memcpy(tab, org, sizeof(int) * taille);
    debut = clock();
    tri_nain(tab, taille);
    fin = clock();
    if (trace == 1) {
        printf("Tableau trie par le nain : "); afficher_tab(tab, taille);
    }
    // verification de l'integrite du tri
    if (memcmp(ref, tab, sizeof(int) * taille) == 0) {
        printf("Tri effectue par le nain en %f sec.\n", (double)(fin - debut) / CLOCKS_PER_SEC);
    } else {
        printf("Erreur : le tri n'est pas correct !\n");
    }
    free(org); free(ref); free(tab);
}


int main(void)
{
    srand(time(NULL));

    // pour tester visuellement
    printf("Tri d'un petit tableau :\n");
    test_tri(10, 1);
    
    // pour avoir des temps de calcul significatifs
    printf("\nTri d'un grand tableau :\n");
    // ajuster le nombre d'elements en fonction de la charge de telesun !
    test_tri(50000, 0);

    return 0;
}

