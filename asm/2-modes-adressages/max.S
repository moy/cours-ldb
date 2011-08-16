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
	
	// return 0;
	xorl %eax, %eax
	leave
	ret
	
.data
	// tableau initial : changer sa valeur pour les tests
tab:  	.long 1, 4, 7, 5, 9, 1, 3, 2, 4, 8, 0
	
