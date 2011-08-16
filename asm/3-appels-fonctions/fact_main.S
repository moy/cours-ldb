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
	ret

.globl erreur_fact
erreur_fact:
	// ...
	ret

	.data
ch1:	.asciz "Entrer n : "
ch2:	.asciz "%u"
ch3:	.asciz "Fact(%u) = %u\n"
ch4:	.asciz "Erreur : fact(%u) est trop grand !\n"

