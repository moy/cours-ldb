#ifdef __APPLE__
#define erreur_fact   _erreur_fact
#define calculer_fact _calculer_fact
#endif

	// unsigned fact(unsigned n)
	/* START CUT */
p_n = 8
	/* END CUT */
	.globl calculer_fact
calculer_fact:
	/* START CUT */
	pushl %ebp
	movl %esp, %ebp
	// pas de variable locale
	// if (n == 0) return 1;
	cmpl $0, p_n(%ebp)
	jne else
	movl $1, %eax
	jmp fin
else:   // return n * fact(n - 1);
	movl p_n(%ebp), %eax
	subl $1, %eax
	pushl %eax
	call calculer_fact
	addl $4, %esp
	mull p_n(%ebp)
	cmpl $0, %edx
	je fin
	movl p_n(%ebp), %eax
	pushl %eax
	call erreur_fact
	addl $4, %esp
fin:
	leave
	/* END CUT */
	// ...
	ret
