#include <stdio.h>
int main() {
	char c = 'a';
	if (c >= 'a' && c <= 'z') {
		printf("'c' est en minuscule\n");
		printf("la majuscule de 'c' est %c\n", c + 'A' - 'a');
	}
	return 0;
}
