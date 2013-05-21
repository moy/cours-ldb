#include <stdio.h>

void increment(int *x) {
	(*x)++;
}

int main() {
	int a = 42;
	increment(&a);
	printf("%d\n", a);
	return 0;
}

