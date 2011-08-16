#ifdef __APPLE__
#define erreur_fact   _erreur_fact
#define calculer_fact _calculer_fact
#endif

	// unsigned fact(unsigned n)
	.globl calculer_fact
calculer_fact:
	// ...
	ret
