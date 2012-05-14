.text
	.globl main
main:
	call sous_prog
	ret

sous_prog:
	movl $42, %eax
	call sous_prog
        // Il faudrait aussi une condition d'arret ...
	movl $0, %ecx
	ret
