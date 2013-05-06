#include <stdio.h>

struct complexe_t {
    float re;
    float im;
};

struct complexe_t plus(struct complexe_t x, struct complexe_t y)
{
    struct complexe_t z;
    z.re = x.re + y.re;
    z.im = x.im + y.im;
    return z;
}

void affiche(struct complexe_t z)
{
    printf("%g + %gi", z.re, z.im);
}

int main(void)
{
    printf("Entrer la partie reelle : ");
    struct complexe_t z;
    scanf("%g", &(z.re));
    printf("Entrer la partie imaginaire : ");
    scanf("%g", &(z.im));
    printf("Somme = "); affiche(plus(z, z)); printf("\n");
    return 0;
}

