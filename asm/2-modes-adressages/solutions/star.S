#ifdef __APPLE__
#define main _main
#define printf _printf
#endif
	.data
fonction_a_appeler:	.skip 4
fmt_un:	.asciz "Il y a un argument (en comptant le nom du programme).\n"
fmt_autre: .asciz "argc != 1 cette fois-ci.\n"
	
	.text
	// affiche_un() et affiche_autre_chose()
	// définies comme des fonctions
affiche_un:
	pushl %ebp
	movl %esp, %ebp
	pushl $fmt_un
	call printf
	addl $4, %esp
	leave
	ret

affiche_autre_chose:
	pushl %ebp
	movl %esp, %ebp
	pushl $fmt_autre
	call printf
	addl $4, %esp
	leave
	ret


	.globl main
main:
	pushl %ebp
	movl %esp, %ebp
	movl 8(%ebp), %eax // Récupération de argc

	cmpl $1, %eax // if (argc == 1) {
	je pile_un
	// $affiche_autre_chose = adresse de début du code de la
	// fonction affiche_autre_chose(). C'est un pointeur de
	// fonction.
	movl $affiche_autre_chose, %ecx
	movl $affiche_autre_chose, fonction_a_appeler
	jmp fin_if
pile_un:
	movl $affiche_un, %ecx
	movl $affiche_un, fonction_a_appeler
fin_if:
	// Ici, %ecx contient un pointeur sur fonction
	// et la variable globale fonction_a_appeler aussi.

	// On peut appeler la fonction pointée par %ecx avec
	// call ...
	// START CUT
	call *%ecx
	// END CUT

	// On peut appeler la fonction pointée par fonction_a_appeler avec
	// call ...
	// START CUT
	call *fonction_a_appeler
	// END CUT

	leave
	ret
