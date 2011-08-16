#include <stdio.h>

#define MULTIPLY(a, b) a*b
#define DEUX 1+1

inline int multiply(int a, int b) {
  return a * b;
}

int main () {
  printf("MULTIPLY(2+2, 2) = %d\n", MULTIPLY(2+2, 2));
  printf("multiply(2+2, 2) = %d\n", multiply(2+2, 2));
  printf("DEUX*DEUX = %d\n", DEUX*DEUX);
  return 0;
}
