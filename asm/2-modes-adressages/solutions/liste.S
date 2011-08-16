.text
	.globl main
main:
	enter $0, $0     // On rentre dans la fonction main

	movl $c1, %eax   // %eax pointe sur le premier élément de la liste.
debut_while:
	// Sauter à fin_while si %eax est nul
	// ...
	// START CUT
	cmpl $0, %eax
	je fin_while
	// END CUT
	movl 0(%eax), %ecx // ecx = eax->val
                           // (pour observer la valeur dans GDB)
	
	// eax = eax->suiv
	// ...
	// START CUT
	movl 4(%eax), %eax // eax = eax->suiv
	// END CUT
	jmp debut_while
fin_while:
	
fin_main:
	xorl %eax, %eax  // Équivalent du "return 0;" en C
	leave            // Sortie de la fonction main.
	ret

.data
// Liste chainée codée en dur dans la section .data
// (en général, on crée plutôt les cellules avec malloc)
c3:	.long 666
	.long c4
c1:	.long 42
	.long c2
c2:	.long 12
	.long c3
c4:	.long 1234
	.long 0
