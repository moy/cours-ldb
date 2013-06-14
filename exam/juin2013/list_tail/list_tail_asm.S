first=0
last=4
val=4
next=0
	// struct list *list_new(char *content) {
content=8
	.globl list_new
list_new:
	pushl %ebp
	movl %esp, %ebp
	subl $20, %esp
//	struct cell * c
sent_next=-8
sent_val=-4
l=-12
p=-16
c=-20
// 	struct list *l = malloc(sizeof(struct list));
	pushl $8
	call malloc
	addl $4, %esp
	movl %eax, l(%ebp)
// 	char *p;
// 	struct cell sent;
// 	if (*content == '\0') {
	movl content(%ebp), %eax
	cmpb $0, (%eax)
	jne else_new
// 		l->first = NULL;
	movl l(%ebp), %eax
	movl $0, first(%eax)
// 		l->last = NULL;
	movl l(%ebp), %eax
	movl $0, last(%eax)
// 		return l;
	movl l(%ebp), %eax
	leave
	ret
// 	}
else_new:

// 	sent.next = NULL;
	movl $0, sent_next(%ebp)
// 	l->last = &sent;
	movl l(%ebp), %eax
	leal sent_next(%ebp), %ecx
	movl %ecx, last(%eax)
// 	p = content;
	movl content(%ebp), %eax
	movl %eax, p(%ebp)
//      while(*p != '\0'; ) {
while_new:
	movl p(%ebp), %eax
	cmpb $0, (%eax)
	je fin_while_new
// 		c = malloc(sizeof(struct cell));
	pushl $8
	call malloc
	addl $4, %esp
	movl %eax, c(%ebp)
// 		c->val = *p;
	movl p(%ebp), %ecx
	movb (%ecx), %cl
	movl c(%ebp), %eax
	movb %cl, val(%eax)
// 		c->next = NULL;
	movl c(%ebp), %eax
	movl $0, next(%eax)
// 		l->last->next = c;
	movl l(%ebp), %eax
	movl last(%eax), %eax
	movl c(%ebp), %ecx
	movl %ecx, next(%eax)
// 		l->last = c;
	movl l(%ebp), %eax
	movl c(%ebp), %ecx
	movl %ecx, last(%eax)
//              p++;
	incl p(%ebp)
// 	}
	jmp while_new
fin_while_new:
// 	l->first = sent.next;
	movl l(%ebp), %eax
	movl sent_next(%ebp), %ecx
	movl %ecx, first(%eax)
// 	return l;
	movl l(%ebp), %eax
// }
	leave
	ret

	
// void list_print_opt(struct list *s) {
s=8
	.globl list_print_opt
list_print_opt:
	pushl %ebp
	movl %esp, %ebp
	pushl %ebx

// 	l = s->first;
	movl s(%ebp), %ebx
	movl first(%eax), %ebx
for_print_opt:
//      while(l != NULL) {
	cmpl $0, %ebx
	je fin_for_print_opt
// 		printf("%c", l->val);
	pushl val(%ebx)
	pushl $fmt_c
	call printf
	addl $8, %esp
//      	l = l->next;
	movl next(%ebx), %ebx
// 	}
	jmp for_print_opt
fin_for_print_opt:	
// }
	popl %ebp
	leave
	ret

	
// void list_cat(struct list *dest, struct list *src) {
dest=8
src=12
	.globl list_cat
list_cat:
	pushl %ebp
	movl %esp, %ebp
//	if (dest->last == NULL) {
	movl dest(%ebp), %eax
	cmpl $0, last(%eax)
	jne else_cat
//		dest->first = src->first;
	movl dest(%ebp), %eax
	movl src(%ebp), %ecx
	movl first(%ecx), %ecx
	movl %ecx, first(%eax)
//	} else {
	jmp endif
else_cat:
// 		dest->last->next = src->first;
	movl src(%ebp), %ecx
	movl first(%ecx), %ecx
	movl dest(%ebp), %eax
	movl last(%eax), %eax
	movl %ecx, next(%eax)
//	}
endif:
//	if (src->last != NULL) {
	movl src(%ebp), %eax
	cmpl $0, last(%eax)
	je else_cat2
//		dest->last = src->last;
	movl src(%ebp), %eax
	movl last(%eax), %eax
	movl dest(%ebp), %ecx
	movl %eax, last(%ecx)
//	}
else_cat2:
// 	free(src);
	pushl src(%ebp)
	call free
	addl $4, %esp
// }
	leave
	ret

####// void list_append(struct list *l, char c) {
####	.globl list_append
####list_append:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####// 	struct cell *cell = malloc(sizeof(struct cell));
####// 	cell->val = c;
####// 	cell->next = NULL;
####// 	if (l->last != NULL) {
####// 		l->last->next = cell;
####// 	} else {
####// 		l->first = cell;
####// 	}
####// 	l->last = cell;
####// }	
####	leave
####	ret
####// 
####
// void list_print(struct list *s) {
s=8
	.globl list_print
list_print:
	// struct cell *l;
l=-4
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp

// 	l = s->first;
	movl s(%ebp), %eax
	movl first(%eax), %eax
	movl %eax, l(%ebp)
for_print:
//      while(l != NULL) {
	cmpl $0, l(%ebp)
	je fin_for_print
// 		printf("%c", l->val);
	movl l(%ebp), %eax
	pushl val(%eax)
	pushl $fmt_c
	call printf
	addl $8, %esp
//      	l = l->next;
	movl l(%ebp), %eax
	movl next(%eax), %eax
	movl %eax, l(%ebp)
// 	}
	jmp for_print
fin_for_print:	
// }
	leave
	ret

// size_t list_len(struct list *s) {
s=8
	.globl list_len
list_len:
	pushl %ebp
	movl %esp, %ebp
// 	size_t len = 0;
	subl $8, %esp
len=-4
l=-8
	movl $0, len(%ebp)
// 	for (struct cell *l = s->first;
	movl s(%ebp), %eax
	movl first(%eax), %eax
	movl %eax, l(%ebp)
for:
//                                      l != NULL;
	cmpl $0, l(%ebp)
	je end_for
// 		len++;
	incl len(%ebp)
//              l = l->next (end for)
	movl l(%ebp), %eax
	movl next(%eax), %eax
	movl %eax, l(%ebp)
// 	}
	jmp for
end_for:
// 	return len;
	movl len(%ebp), %eax
	leave
	ret


// static void plus_one(char *c, void *arg) {
plus_one:
	pushl %ebp
	movl %esp, %ebp

// 	(void)c;
arg=12
// 	size_t *count = (size_t *)arg;
// 	++(*count);
	movl arg(%ebp), %eax
	incl (%eax)
// }
	leave
	ret

// size_t list_len_iter(struct list *s) {
s=8
	.globl list_len_iter
list_len_iter:
	pushl %ebp
	movl %esp, %ebp
// 	size_t count = 0;
count=-4
	subl $4, %esp
	movl $0, count(%ebp)
// 	list_iterate(s, plus_one, &count);
	leal count(%ebp), %eax
	pushl %eax
	pushl $plus_one
	pushl s(%ebp)
	call list_iterate
	addl $12, %esp
// 	return count;
	movl count(%ebp), %eax
// }
	leave
	ret

// static void print(char *c, void *arg) {
c=8
arg=12
	.globl print
print:
	pushl %ebp
	movl %esp, %ebp

// 	printf("%c", *c);
	movl c(%ebp), %eax
	pushl (%eax)
	pushl $fmt_c
	call printf
	addl $8, %esp
// }
	leave
	ret
####
####// void list_print_iter(struct list *s) {
####	.globl list_print_iter
####list_print_iter:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####// 	list_iterate(s, print, NULL);
####// }
####	leave
####	ret
####	
####// static void to_upper(char *c, void *arg) {
####	.globl to_upper
####to_upper:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####	
####// 	(void)arg;
####// 	if (*c < 'z' && *c > 'a') {
####// 		*c += 'A' - 'a';
####// 	}
####// }
####	leave
####	ret
####
####// void list_to_upper(struct list *s) {
####	.globl list_to_upper
####list_to_upper:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####// 	list_iterate(s, to_upper, NULL);
####// }
####	leave
####	ret
####
####// void list_free(struct list *s) {
####	.globl list_free
####list_free:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####// 	struct cell *l = s->first; 
####// 	while (l != NULL) {
####// 		struct cell *tmp = l;
####// 		l = l->next;
####// 		free(tmp);
####// 	}
####// 	free(s);
####// }
####	leave
####	ret
####
####// void list_iterate(struct list *s, void (*f)(char *, void *), void *arg) {
####	.globl list_iterate
####list_iterate:
####	pushl %ebp
####	movl %esp, %ebp
####
####	call abort
####	
####	
####// 	for (struct cell *l = s->first; l != NULL; l = l->next) {
####// 		f(&l->val, arg);
####// 	}
####	leave
####	ret
####
.data
fmt_c:	.asciz "%c"
