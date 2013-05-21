	// int palindrome(char *chaine)
	/* START CUT */
p_chaine = 8
	/* END CUT */
est_palindrome:
	.globl est_palindrome
	/* START CUT */
	enter $8, $0
	// unsigned inf
inf = -4
	// unsigned sup
sup = -8
	// for (inf = 0,
	movl $0, inf(%ebp)
	// sup = strlen(chaine) - 1;
	movl p_chaine(%ebp), %eax
	pushl %eax
	call strlen
	addl $4, %esp
	subl $1, %eax
	movl %eax, sup(%ebp)
for:
	// (inf < sup) && (chaine[inf] == chaine[sup]);
	movl inf(%ebp), %eax
	cmpl sup(%ebp), %eax
	jae fin_for
	movl p_chaine(%ebp), %eax
	movl inf(%ebp), %ecx
	movl sup(%ebp), %edx
	movb (%eax, %ecx), %cl
	cmpb (%eax, %edx), %cl
	jne fin_for
	// ++inf,
	addl $1, inf(%ebp)
	// --sup);
	subl $1, sup(%ebp)
	jmp for
fin_for:
	// return inf >= sup
	movl inf(%ebp), %eax
	cmpl sup(%ebp), %eax
	jb palindrome_fin
	movl $1, %eax
	leave
	ret
	
palindrome_fin:
	xorl %eax, %eax
	leave
	/* END CUT */
	ret
