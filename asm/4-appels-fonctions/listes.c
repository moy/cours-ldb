
#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// le type cellule d'une liste chainee
struct cellule_t {
    int val;
    struct cellule_t *suiv;
};

// cree une liste chainee a partir d'un tableau d'entiers termine par -1
// les elements sont inseres dans le meme ordre que dans le tableau initial
struct cellule_t *cree_liste(int tab[])
{
    struct cellule_t sent;
    struct cellule_t *queue;
    for (queue = &sent; *tab != -1; tab++) {
        queue->suiv = malloc(sizeof(struct cellule_t));
        assert(queue->suiv != NULL);
        queue = queue->suiv;
        queue->val = *tab;
    } 
    queue->suiv = NULL;
    return sent.suiv;
}

// affiche une liste chainee d'entiers
void affiche_liste(struct cellule_t *liste)
{
    for (; liste != NULL; liste = liste->suiv) {
        printf("%d -> ", liste->val);
    }
    printf("FIN\n");
}

// prototype de la fonction externe de decoupage, implantee en assembleur
struct cellule_t *decoupe(struct cellule_t *l, struct cellule_t **l1, struct cellule_t **l2);

// une fonction de test basique
void test(int tableau[])
{
    struct cellule_t *liste, *l1, *l2;
    liste = cree_liste(tableau);
    printf("Liste initiale : ");
    affiche_liste(liste);
    liste = decoupe(liste, &l1, &l2);
    printf("Liste initiale apres le decoupage : ");
    affiche_liste(liste);
    printf("Liste des elements impairs : ");
    affiche_liste(l1);
    printf("Liste des elements pairs : ");
    affiche_liste(l2);
}

int main(void)
{
    const int taille_tab = 11;
    int tableau[taille_tab];
    srand(time(NULL));

    printf("** Test d'un tableau quelconque **\n");
    for (int i = 0; i < taille_tab - 1; i++) {
        tableau[i] = rand() % 10;
    }
    tableau[taille_tab - 1] = -1;
    test(tableau);

    printf("\n** Test d'un tableau avec seulement des elements pairs **\n");
    for (int i = 0; i < taille_tab - 1; i++) {
        tableau[i] = (rand() % 10) & ~1;
    }
    tableau[taille_tab - 1] = -1;
    test(tableau);

    printf("\n** Test d'un tableau avec seulement des elements impairs **\n");
    for (int i = 0; i < taille_tab - 1; i++) {
        tableau[i] = (rand() % 10) | 1;
    }
    tableau[taille_tab - 1] = -1;
    test(tableau);

    printf("\n** Test d'un tableau vide **\n");
    tableau[0] = -1;
    test(tableau);

    return 0;
}

