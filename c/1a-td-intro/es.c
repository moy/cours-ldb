#include <stdio.h>

int main(void)
{
    printf("Entrer un entier signe : ");
    int entier;
    scanf("%i", &entier);

    printf("Entrer un entier naturel : ");
    unsigned naturel;
    scanf("%u", &naturel);

    printf("Vous avez entre %i et %u\n", entier, naturel);

    return 0;
}

