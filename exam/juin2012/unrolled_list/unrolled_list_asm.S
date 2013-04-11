offset_first = 0
offset_last = 4
	
offset_size = 0
offset_next = 4
offset_content = 8
/* static struct unrolled_list_elem *unrolled_list_elem(char *content) { */
/* 	size_t len = strlen(content); */
/* 	struct unrolled_list_elem *elem = malloc(sizeof(struct unrolled_list_elem) + len); */
/* 	elem->size = len; */
/* 	memcpy(elem->content, content, len); */
/* 	elem->next = NULL; */
/* 	return elem; */
/* } */

/* static struct unrolled_list *unrolled_list_wrap(struct unrolled_list_elem *e) { */
/* 	struct unrolled_list *res = malloc(sizeof(struct unrolled_list)); */
/* 	res->first = e; */
/* 	res->last = e; */
/* 	return res; */
/* } */

/* struct unrolled_list *unrolled_list_new(char *content) { */
arg_content = 8	
	.globl unrolled_list_new
unrolled_list_new:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp
/* 	struct unrolled_list_elem *elem = unrolled_list_elem(content); */
	pushl arg_content(%ebp)
	call unrolled_list_elem
	addl $4, %esp
/* 	return unrolled_list_wrap(elem); */
	pushl %eax
	call unrolled_list_wrap
	addl $4, %esp
/* } */
	leave
	ret

	.section .rodata
fmt_star_s:	.asciz "%.*s"
	.text
/* void unrolled_list_print(struct unrolled_list *r) { */
	.globl unrolled_list_print
loc_cur = -4
arg_r = 8
unrolled_list_print:
	pushl %ebp
	movl %esp, %ebp
/* 	struct unrolled_list_elem *cur; */
	subl $4, %esp
/* 	for (cur = r->first; */
	movl arg_r(%ebp), %eax
	movl offset_first(%eax), %eax
	movl %eax, loc_cur(%ebp)
/*	     cur != NULL; // for condition */
debut_for_print:
	cmpl $0, loc_cur(%ebp)
	je end_for_print
/* 		printf("%.*s", cur->size, cur->content); */
	movl loc_cur(%ebp), %eax
	addl $offset_content, %eax ## Gros piège ici !
	pushl %eax
	movl loc_cur(%ebp), %eax
	pushl offset_size(%eax)
	pushl $fmt_star_s
	call printf
	addl $12, %esp
/*	cur = cur->next) { // for increment */
	movl loc_cur(%ebp), %eax
	movl offset_next(%eax), %eax
	movl %eax, loc_cur(%ebp)
/* 	} */
	jmp debut_for_print
end_for_print:
	leave
	ret
/* } */
	
	.globl unrolled_list_print_opt
arg_r = 8
unrolled_list_print_opt:
	pushl %ebp
	movl %esp, %ebp
/* 	struct unrolled_list_elem *cur; */
	pushl %ebp
	/* -> %ebx */
/* 	for (cur = r->first; */
	movl arg_r(%ebp), %eax
	movl offset_first(%eax), %ebx
/*	     cur != NULL; // for condition */
debut_for_print_opt:
	cmpl $0, %ebx
	je end_for_print_opt
/* 		printf("%.*s", cur->size, cur->content); */
	leal offset_content(%ebx), %eax
	pushl %eax
	pushl offset_size(%ebx)
	pushl $fmt_star_s
	call printf
	addl $12, %esp
/*	cur = cur->next) { // for increment */
	movl offset_next(%ebx), %ebx
/* 	} */
	jmp debut_for_print_opt
end_for_print_opt:
	popl %ebx
	leave
	ret
/* } */

	
/* size_t unrolled_list_len(struct unrolled_list *r) { */
param_r = 8	
	.globl unrolled_list_len
unrolled_list_len:
	pushl %ebp
	movl %esp, %ebp
/* 	struct unrolled_list_elem *cur; */
/* 	size_t len = 0; */
loc_len = -8
loc_cur = -4
	subl $(4+4), %esp
	movl $0, loc_len(%ebp)
/* 	for (cur = r->first; */
	movl param_r(%ebp), %eax
	movl offset_first(%eax), %eax
	movl %eax, loc_cur(%ebp)
/*                           cur != NULL; */
debut_for:
	cmpl $0, loc_cur(%ebp)
	je fin_for
/* 		len += cur->size; */
	movl loc_cur(%ebp), %eax
	movl offset_size(%eax), %eax
	addl %eax, loc_len(%ebp)
/*                                            cur = cur->next) { */
	movl loc_cur(%ebp), %eax
	movl offset_next(%eax), %eax
	movl %eax, loc_cur(%ebp)
/* 	} */
	jmp debut_for
fin_for:	
/* 	return len; */
	movl loc_len(%ebp), %eax
	leave
	ret
/* } */

/* void unrolled_list_append(struct unrolled_list *dest, char *to_append) { */
/* 	struct unrolled_list_elem *last = dest->last; */
/* 	last->next = unrolled_list_elem(to_append); */
/* 	dest->last = last->next; */
/* } */

/* struct unrolled_list *unrolled_list_pack(struct unrolled_list *r) { */
	.globl unrolled_list_pack
	param_r=8
unrolled_list_pack:
	pushl %ebp
	movl %esp, %ebp
	subl $16, %esp
	loc_len=-4
	loc_elem=-8
	loc_current=-12
	loc_cur=-16
/* 	size_t len = unrolled_list_len(r); */
	pushl param_r(%ebp)
	call unrolled_list_len
	addl $4, %esp
	movl %eax, loc_len(%ebp)
/* 	struct unrolled_list_elem *elem = malloc(sizeof(struct unrolled_list_elem) + len); */
	movl loc_len(%ebp), %eax
	addl $8, %eax
	pushl %eax
	call malloc
	addl $4, %esp
	movl %eax, loc_elem(%ebp)
/* 	char *current = elem->content; */
	movl loc_elem(%ebp), %eax
	addl $offset_content, %eax
	movl %eax, loc_current(%ebp)
/* 	struct unrolled_list_elem *cur; */
/* 	elem->size = len; */
	movl loc_len(%ebp), %eax
	movl loc_elem(%ebp), %ecx
	movl %eax, offset_size(%ecx)
/* 	elem->next = NULL; */
	movl loc_elem(%ebp), %ecx
	movl $0, offset_next(%ecx)
/* 	for (cur = r->first; */
	movl param_r(%ebp), %eax
	movl offset_first(%eax), %eax
	movl %eax, loc_cur(%ebp)
debut_for_pack:	
/*                           cur != NULL; */
	cmpl $0, loc_cur(%ebp)
	je fin_for_pack
/* 		memcpy(current, cur->content, cur->size); */
	movl loc_cur(%ebp), %eax
	pushl offset_size(%eax)
	leal offset_content(%eax), %eax
	pushl %eax
	pushl loc_current(%ebp)
	call memcpy
	addl $12, %esp
/* 		current += cur->size; */
	movl loc_cur(%ebp), %eax
	movl offset_size(%eax), %eax
	addl %eax, loc_current(%ebp)
/*                                       cur = cur->next) { */
	movl loc_cur(%ebp), %eax
	movl offset_next(%eax), %eax
	movl %eax, loc_cur(%ebp)
	jmp debut_for_pack
/* 	} */
fin_for_pack:	
/* 	return unrolled_list_wrap(elem); */
	pushl loc_elem(%ebp)
	call unrolled_list_wrap
	addl $12, %esp
/* } */
	leave
	ret

/* void unrolled_list_free(struct unrolled_list *r) { */
/* 	struct unrolled_list_elem *cur; */
/* 	for (cur = r->first; cur != NULL;) { */
/* 		struct unrolled_list_elem *tmp = cur; */
/* 		cur = cur->next; */
/* 		free(tmp); */
/* 	} */
/* 	free(r); */
/* } */
