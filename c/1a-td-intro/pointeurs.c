#include <stdio.h>

struct ma_struct_t {
    int i;
    char c;
};

void echange(int *a, int *b)
{
    int t = *a; *a = *b; *b = t;
}

int main(void)
{
    int i = 5;
    int *ptr = &i;
    *ptr = 10;
    printf("Adresse de i : 0x%08X, valeur de i : %i\n", (unsigned)ptr, i);

    int j = 20;
    echange(&i, &j);
    printf("i = %i, j = %i\n", i, j);

    char chaine[] = "azerty";
    for (char *p = chaine; *p; p++)
        printf("%c", *p);
    printf("\n");

    int tab[] = {1, 2, 3, 4, 5, -1};
    for (int *p = tab; *p != -1; p++)
        printf("Adresse : 0x%08X, valeur : %i\n", (unsigned)p, *p);

    struct ma_struct_t s = {-4, 'a'};
    struct ma_struct_t *p = &s;
    (*p).i = 4; p->c = 'A';
    printf("%i %c\n", p->i, s.c);

    return 0;
}

