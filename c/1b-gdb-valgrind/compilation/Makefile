# Ceci est un Makefile d'exemple, qui n'utilise pas les fonctions
# avancees de make.

# Rappel : la syntaxe d'une règle est la suivante :
# cible: dependance1 dependance2 ...
# <-- tab -->action pour construire la cible.

# Édition de liens
bonjour: au-revoir.o bonjour.o ppal.o
	gcc au-revoir.o bonjour.o ppal.o -o bonjour

# Compilation (séparée)

au-revoir.o: au-revoir.c au-revoir.h
	gcc -c au-revoir.c

bonjour.o: bonjour.c bonjour.h
	gcc -c bonjour.c

ppal.o: ppal.c bonjour.h au-revoir.h
	gcc -c ppal.c
