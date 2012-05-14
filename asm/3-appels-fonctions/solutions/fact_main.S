#ifdef __APPLE__
#define printf _printf
#define scanf _scanf
#define main _main
#define exit _exit
#define erreur_fact   _erreur_fact
#define calculer_fact _calculer_fact
#endif

	.globl main

	.text
	// int main(void)
main:
	/* START CUT */
	push %ebp
	movl %esp, %ebp
	subl $8, %esp

	// unsigned n;
n = -4
	// unsigned f;
f = -8
	// printf("Entrer n : ");
	pushl $ch1
	call printf
	addl $4, %esp
	// scanf("%u", &n);
	leal n(%ebp), %eax
	pushl %eax
	pushl $ch2
	call scanf
	addl $8, %esp
	// f = fact(n);
	pushl n(%ebp)
	call calculer_fact
	addl $4, %esp
	movl %eax, f(%ebp)
	// printf("Fact(%u) = %u\n", n, f);
	pushl f(%ebp)
	pushl n(%ebp)
	pushl $ch3
	call printf
	addl $12, %esp
	// return 0;
	xorl %eax, %eax
	leave
	/* END CUT */
	ret

.globl erreur_fact
erreur_fact:
	/* START CUT */
p_n = 8
	pushl %ebp
	movl %esp, %ebp

	pushl p_n(%ebp)
	pushl $ch4
	call printf
	addl $8, %esp

	pushl $1
	call exit
	// On ne devrait jamais atteindre ce point du programme
	// mais on garde les bonnes habitudes.
	addl $4, %esp
	
	leave
	/* END CUT */
	// ...
	ret

	.data
ch1:	.asciz "Entrer n : "
ch2:	.asciz "%u"
ch3:	.asciz "Fact(%u) = %u\n"
ch4:	.asciz "Erreur : fact(%u) est trop grand !\n"

