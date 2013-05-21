#ifdef __APPLE__
#define main _main
#endif

.text
	.globl main
main:
	jmp sous_prog
apres_sous_prog:

	jmp sous_prog2
apres_sous_prog2:
	
	ret

sous_prog:
	movl $42, %eax
	movl $0, %ecx
	jmp apres_sous_prog

sous_prog2:
	movl $42, %edx
	movl %eax, %ecx
	jmp apres_sous_prog2

