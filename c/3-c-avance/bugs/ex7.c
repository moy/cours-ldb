/*
  Des tableaux, des pointeurs, ...
*/

#include <stdio.h>

int *a, *b;

void f(int x) {
	int i[3];
	i[0] = x;
	i[1] = x + 1;
	i[2] = x + 2;
	a = i;
}  

void g(int x) {
	int i[3];
	i[0] = x;
	i[1] = x + 1;
	i[2] = x + 2;
	b = i;
}  

int main() {
	f(1); /* Modifie a */
	printf("a = {%d,%d,%d}\n", a[0], a[1], a[2]);
	g(2); /* Modifie b */
	printf("a = {%d,%d,%d}\n", a[0], a[1], a[2]);
	return 0;
}
