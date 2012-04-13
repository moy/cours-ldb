#include <stdio.h>

unsigned pgcd(unsigned a, unsigned b)
{
    while (a != b) { // attention : different s'ecrit != et pas /=
        if (a < b) {
            b = b - a;
        } else {
            a = a - b;
        }
    }
    return a;
}

int main(void)
{
    printf("Entrer a : ");
    unsigned a;
    scanf("%u", &a);
    printf("Entrer b : ");
    unsigned b;
    scanf("%u", &b);
    printf("pgcd(a, b) = %u\n", pgcd(a, b));
    return 0;
}

