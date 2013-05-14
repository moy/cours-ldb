.globl main
	.text
main:
	// debut de la fonction
	enter $0, $0
	
	// on stocke l'adresse de la chaine dans %edx
	movl $chaine, %edx
	// on initialise un compteur à 0
	movl $0, %ecx
	
	// completer ici avec le calcul de la longueur de la chaine
debut_while:
	// ... (condition du while)

	// ... (passage au caractère suivant)
	jmp debut_while
fin_while:
	// return 0;
	xorl %eax, %eax
	leave
	ret

	.data
// la chaine : changer sa valeur pour vos tests
chaine: .asciz "azerty" // on peut utiliser aussi .string sous
                        // Linux (pas sous MacOS)
senti:  .asciz "zzzzzz" // cette zone memoire NE DOIT PAS etre
                        // accedee
	
