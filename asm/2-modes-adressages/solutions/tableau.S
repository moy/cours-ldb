.data
t1:	.long 1
t2:	.long 12
t3:	.long 3
t4:	.long 5
t5:	.long 25
.text
	.globl main
main:
	enter $0, $0     // On rentre dans la fonction main

	xorl %eax, %eax  // Remettre %eax à 0.

	// Compléter ici en utilisant plusieurs fois addl ..., %eax.
	// Pour calculer la somme des éléments dans %eax.
	// START CUT
	addl t1, %eax
	addl t2, %eax
	addl t3, %eax
	addl t4, %eax
	addl t5, %eax
	// END CUT

fin_main:
	xorl %eax, %eax  // Équivalent du "return 0;" en C
	leave            // Sortie de la fonction main.
	ret
