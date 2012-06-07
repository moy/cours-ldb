/********************************************************************
 * Copyright (C) 2012 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#include "unrolled_list.h"
#include <string.h>
#include <stdio.h>

// Cree une ``unrolled list'' contenant les caracteres de la chaine C
// ``content'' (terminée par un '\0').
struct unrolled_list_elem *unrolled_list_elem(char *content) {
	size_t len = strlen(content);
	struct unrolled_list_elem *elem = malloc(sizeof(struct unrolled_list_elem) + len);
	elem->size = len;
	memcpy(elem->content, content, len);
	elem->next = NULL;
	return elem;
}

struct unrolled_list *unrolled_list_wrap(struct unrolled_list_elem *e) {
	struct unrolled_list *res = malloc(sizeof(struct unrolled_list));
	res->first = e;
	res->last = e;
	return res;
}

void unrolled_list_append(struct unrolled_list *dest, char *to_append) {
	struct unrolled_list_elem *last = dest->last;
	last->next = unrolled_list_elem(to_append);
	dest->last = last->next;
}

void unrolled_list_free(struct unrolled_list *r) {
	struct unrolled_list_elem *cur;
	for (cur = r->first; cur != NULL;) {
		struct unrolled_list_elem *tmp = cur;
		cur = cur->next;
		free(tmp);
	}
	free(r);
}
