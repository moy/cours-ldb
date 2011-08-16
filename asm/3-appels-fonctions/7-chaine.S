#ifdef __APPLE__
#define printf _printf
#define scanf _scanf
#define main _main
#endif

	.globl main
main:
	pushl %ebp
	movl %esp, %ebp
	// Sauvegarde du registre non-scratch par
	// l'appelé
	pushl %ebx

	movl $chaine, %ecx
	
	// On n'utilise que %bl, mais on remplit
	// le reste de %ebx avec des 0.
	movl $0, %ebx
while:
	cmpb $0, (%ecx)
	je fin_while
	movb (%ecx), %bl
	// Sauvegarde de %ecx
	pushl %ecx
	// On empile les arguments de printf
	pushl %ebx
	pushl $fmt
	call printf
	addl $8, %esp
	// Restauration de %ecx
	popl %ecx
	incl %ecx // équivalent à addl $1, %ecx
	jmp while

fin_while:
	// Restauration de registres non-scratch.
	popl %ebx
	leave
	ret
.data
chaine: .asciz "Hello\n"
fmt:	.asciz "%c"
