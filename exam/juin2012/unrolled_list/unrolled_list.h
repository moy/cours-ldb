/********************************************************************
 * Copyright (C) 2012 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#ifndef ROPE_H
#define ROPE_H

#include <stdlib.h>

struct unrolled_list_elem {
	size_t size;
	struct unrolled_list_elem *next;
	char content[];
};

struct unrolled_list {
	struct unrolled_list_elem *first;
	struct unrolled_list_elem *last;
};

extern void unrolled_list_append(struct unrolled_list *dest, char *to_append);
extern struct unrolled_list *unrolled_list_new(char *content);
extern void unrolled_list_print(struct unrolled_list *);
extern void unrolled_list_print_opt(struct unrolled_list *);
extern size_t unrolled_list_len(struct unrolled_list *r);
extern struct unrolled_list *unrolled_list_pack(struct unrolled_list *r);
extern void unrolled_list_free(struct unrolled_list *r);

// Private functions (used by C and ASM)
extern struct unrolled_list_elem *unrolled_list_elem(char *content);
extern struct unrolled_list *unrolled_list_wrap(struct unrolled_list_elem *e);
#endif // ROPE_H
