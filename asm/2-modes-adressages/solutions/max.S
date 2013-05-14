.text
	.globl main
main:	
	// debut de la fonction
	enter $0, $0
	
	xorl %edx, %edx // Maximum trouvé
	xorl %eax, %eax // Indice dans le tableau
	movl $tab, %ecx // Adresse de la première case du tableau
	// completer ici avec le code de recherche du maximum
	// ...
	// START CUT
debut_while:
	// while (*t != 0) {
	cmpl $0, (%ecx, %eax, 4)
	je fin_while

	//   if (*t > max) {
	cmpl %edx, (%ecx, %eax, 4)
	jle pas_max
	//     max = *t;
	movl (%ecx, %eax, 4), %edx
	//   }
pas_max:
	addl $1, %eax
	// }
	jmp debut_while
fin_while:	
	// END CUT
	
	// return 0;
	xorl %eax, %eax
	leave
	ret
	
.data
	// tableau initial : changer sa valeur pour les tests
tab:  	.long 1, 4, 7, 5, 9, 1, 3, 2, 4, 8, 0
	
