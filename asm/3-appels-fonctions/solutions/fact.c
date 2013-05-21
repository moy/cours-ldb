#include <stdio.h>
#include <stdlib.h>

unsigned calculer_fact(unsigned);

void erreur_fact(unsigned n)
{
    printf("Fact(%u) ne tient pas sur 32 bits !\n", n);
    // cette fonction termine proprement le programme
    exit(1);
}

int main(void)
{
    printf("Valeur de n : ");
    unsigned n;
    scanf("%u", &n);
    printf("Fact(%u) = %u\n", n, calculer_fact(n));
    return 0;
}
