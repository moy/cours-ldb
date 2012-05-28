/********************************************************************
 * Copyright (C) 2012 by Ensimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/
.section .rodata
hello:	.ascii "hello"
fmt:	.asciz "a = %.*s\n"
.text
	
	offset_size = 0
	offset_content = 4
	## int main(void) {
.globl main
main:
	pushl %ebp
	movl %esp, %ebp
	## struct array *a = malloc(sizeof(struct array) + 5);
loc_a = -4
	subl $4, %esp
	pushl $(4+5)
	call malloc
	addl $4, %esp
	movl %eax, loc_a(%ebp)
	
	## a->size = 5;
	movl loc_a(%ebp), %eax
	movl $5, offset_size(%eax)
	## memcpy(a->content, "hello", 5);
	pushl $5
	pushl $hello
	movl loc_a(%ebp), %eax
	addl $offset_content, %eax # /!\ piège ici
	pushl %eax
	call memcpy
	addl $12, %esp
	## printf("a = %.*s\n", a->size, a->content);
	movl loc_a(%ebp), %eax
	addl $offset_content, %eax # /!\ même piège ici
	pushl %eax
	movl loc_a(%ebp), %eax
	pushl offset_size(%eax)
	pushl $fmt
	call printf
	addl $12, %esp

	leave
	ret
	
