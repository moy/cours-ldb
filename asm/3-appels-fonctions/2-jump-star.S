#ifdef __APPLE__
#define main _main
#endif

.text
	.globl main
main:
	movl $apres_sous_prog, %edx
	jmp sous_prog
apres_sous_prog:

	movl $apres_sous_prog2, %edx
	jmp sous_prog
apres_sous_prog2:

	ret /* Fin du main. */

sous_prog:
	movl $42, %eax
	movl $0, %ecx
	jmp *%edx
