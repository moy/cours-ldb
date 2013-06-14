/********************************************************************
 * Copyright (C) 2012 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#include "list_tail.h"
#include <string.h>
#include <stdio.h>

/**** C-only ***/

void list_append(struct list *l, char c) {
	struct cell *cell = malloc(sizeof(struct cell));
	cell->val = c;
	cell->next = NULL;
	if (l->last != NULL) {
		l->last->next = cell;
	} else {
		l->first = cell;
	}
	l->last = cell;
}

void list_free(struct list *s) {
	struct cell *l = s->first; 
	while (l != NULL) {
		struct cell *tmp = l;
		l = l->next;
		free(tmp);
	}
	free(s);
}

void list_iterate(struct list *s, void (*f)(char *, void *), void *arg) {
	for (struct cell *l = s->first; l != NULL; l = l->next) {
		f(&l->val, arg);
	}
}

static void to_upper(char *c, void *arg) {
	(void)arg;
	if (*c <= 'z' && *c >= 'a') {
		*c += 'A' - 'a';
	}
}

void list_to_upper(struct list *s) {
	list_iterate(s, to_upper, NULL);
}

/*** Pas utilisés ***/

static void print(char *c, void *arg) {
	(void)arg;
	printf("%c", *c);
}

void list_print_iter(struct list *s) {
	list_iterate(s, print, NULL);
}
