/********************************************************************
 * Copyright (C) 2012 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#include "unrolled_list.h"
#include <stdio.h>
#include <string.h>

struct unrolled_list *unrolled_list_new(char *content) {
	struct unrolled_list_elem *elem = unrolled_list_elem(content);
	return unrolled_list_wrap(elem);
}

void unrolled_list_print_opt(struct unrolled_list *r) {
	unrolled_list_print(r);
}

void unrolled_list_print(struct unrolled_list *r) {
	struct unrolled_list_elem *cur;
	for (cur = r->first; cur != NULL; cur = cur->next) {
		//printf("print[%d] = %.*s.\n", cur->size, cur->size, cur->content);
		printf("%.*s", cur->size, cur->content);
	}
}

size_t unrolled_list_len(struct unrolled_list *r) {
	struct unrolled_list_elem *cur;
	size_t len = 0;
	for (cur = r->first; cur != NULL; cur = cur->next) {
		len += cur->size;
	}
	return len;
}

struct unrolled_list *unrolled_list_pack(struct unrolled_list *r) {
	size_t len = unrolled_list_len(r);
	struct unrolled_list_elem *elem = malloc(sizeof(struct unrolled_list_elem) + len);
	char *current = elem->content;
	struct unrolled_list_elem *cur;
	elem->size = len;
	elem->next = NULL;
	
	for (cur = r->first; cur != NULL; cur = cur->next) {
		memcpy(current, cur->content, cur->size);
		current += cur->size;
	}
	return unrolled_list_wrap(elem);
}
