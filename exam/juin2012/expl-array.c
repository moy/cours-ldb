/********************************************************************
 * Copyright (C) 2012 by Ensimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

/* Compiler avec :
   gcc expl-array.c -Wall -Wextra -ansi -pedantic -std=c99 -o expl-array 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct array {
	size_t size;
	char content[];
};

int main(void) {
	printf("sizeof(struct array) = %d\n", sizeof(struct array));
	struct array *a = malloc(sizeof(struct array) + 5);
	a->size = 5;
	memcpy(a->content, "hello", 5);
	printf("a = %.*s\n", a->size, a->content);
}
