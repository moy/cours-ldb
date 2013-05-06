#include <stdio.h>

unsigned somme_rec(unsigned n)
{
  if (0 < n) {
    return 0;
  } else {
    return n + somme_rec(n - 1);
  }
}

unsigned somme_iter(unsigned n)
{
    unsigned r = 0;
    for (unsigned i = 0; i <= n; i++) {
      r += i;
    }
    return r;
}

int main(void)
{
    printf("Entrer n : ");
    unsigned n;
    scanf("%u", &n);
    printf("Somme des %d premiers entiers :\n", n);
    printf("  - recursivement : %u\n", somme_rec(n));
    printf("  - iterativement : %u\n", somme_iter(n));
    return 0;
}

