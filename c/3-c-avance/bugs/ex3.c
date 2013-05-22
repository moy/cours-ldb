/*
  Une boucle for qui ne s'arrête pas quand il faut.
*/
#include <stdio.h>

int main() {
	unsigned int i;
	for (i = 12; i >= 0; --i) {
		printf("i = %d\n", i);
	}
}
