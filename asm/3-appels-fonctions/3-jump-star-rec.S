#ifdef __APPLE__
#define main _main
#endif

.text
	.globl main
main:
	movl $apres_sous_prog, %edx
	jmp sous_prog
apres_sous_prog:

	ret /* Fin du main. */

sous_prog:
	movl $42, %eax

	/* Ecrase %edx :-( */
	movl $apres_sous_prog2, %edx
	jmp sous_prog
apres_sous_prog2:

	movl $0, %ecx
	jmp *%edx
