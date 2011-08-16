#include <time.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

struct cellule_t {
    int val;
    struct cellule_t *suiv;
};

void afficher(struct cellule_t *liste)
{
    for (; liste != NULL; liste = liste->suiv) {
        printf("%i -> ", liste->val);
    }
    printf("FIN\n");
}

void inserer_tete(struct cellule_t **liste, int v)
{
    struct cellule_t *cell = malloc(sizeof(struct cellule_t));
    assert(cell != NULL);
    cell->val = v; cell->suiv = *liste;
    *liste = cell;
}

void inserer_queue(struct cellule_t **liste, int v)
{
    struct cellule_t sent = {-1, *liste};
    struct cellule_t *queue;
    for (queue = &sent; queue->suiv != NULL; queue = queue->suiv);
    queue->suiv = malloc(sizeof(struct cellule_t));
    assert(queue->suiv != NULL);
    queue->suiv->val = v; queue->suiv->suiv = NULL;
    *liste = sent.suiv;
}

void supprimer_premier(struct cellule_t **liste, int v)
{
    struct cellule_t sent = {-1, *liste};
    struct cellule_t *p;
    for (p = &sent; (p->suiv != NULL) && (p->suiv->val != v); p = p->suiv);
    if (p->suiv != NULL) {
        struct cellule_t *tmp = p->suiv;
        p->suiv = tmp->suiv;
        free(tmp);
    }
    *liste = sent.suiv;
}

int main(void)
{
    struct cellule_t *liste = NULL;
    for (int i = 6; i < 10; i++) {
        inserer_queue(&liste, i);
        afficher(liste);
    }
    for (int i = 5; i > 0; i--) {
        inserer_tete(&liste, i);
        afficher(liste);
    }
    srand(time(NULL));
    while (liste != NULL) {
        supprimer_premier(&liste, rand() % 10);
        afficher(liste);
    }
    return 0;
}
