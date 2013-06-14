/********************************************************************
 * Copyright (C) 2012 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#include "list_tail.h"
#include <stdio.h>
#include <string.h>

struct list *list_new(char *content) {
	struct cell *c;
	struct list *l = malloc(sizeof(struct list));
	char *p;
	struct cell sent; // 8 octets
	if (content[0] == '\0') {
		l->first = NULL;
		l->last = NULL;
		return l;
	}
	sent.next = NULL;
	l->last = &sent;
	for (p = content; *p != '\0'; ++p) {
		c = malloc(sizeof(struct cell));
		c->val = *p;
		c->next = NULL;
		l->last->next = c;
		l->last = c;
	}
	l->first = sent.next;
	return l;
}

size_t list_len(struct list *s) {
	size_t len = 0;
	struct cell *l;
	for (l = s->first; l != NULL; l = l->next) {
		len++;
	}
	return len;
}

void list_cat(struct list *dest, struct list *src) {
	if (dest->last == NULL) {
		dest->first = src->first;
	} else {
		dest->last->next = src->first;
	}
	if (src->last != NULL) {
		dest->last = src->last;
	}
	free(src);
}

void list_print(struct list *s) {
	struct cell *l;
	for (l = s->first; l != NULL; l = l->next) {
		printf("%c", l->val);
	}
}

void list_print_opt(struct list *s) {
	list_print(s);
}


static void plus_one(char *c, void *arg) {
	(void)c;
	size_t *count = (size_t *)arg;
	++(*count);
}

size_t list_len_iter(struct list *s) {
	size_t count = 0;
	list_iterate(s, plus_one, &count);
	return count;
}
