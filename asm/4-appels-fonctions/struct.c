#include <stdio.h>

// une structure de donnees simple
struct structure_t {
    int entier;
    int *ptr;
};

// fonction qui sera appellee par la fonction affichage
//   qui est elle a ecrire en assembleur
void affiche(int entier, int *ptr)
{
    printf("entier = %i, ptr = 0x%X\n", entier, (unsigned)ptr);
}

// fonction a ecrire en assembleur
void affichage(struct structure_t);

// fonction a ecrire en assembleur
void modification(int, int*, struct structure_t*);

int main(void)
{
    struct structure_t s = {-1, (int*)0x0ABCDEF0};
    affichage(s);
    modification(5, (int*)0x12345678, &s);
    affichage(s);
    return 0;
}

