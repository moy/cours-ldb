# Avec les règles implicites de GNU Make, il n'y a pas grand chose à
# écrire :-)

CFLAGS=-g

test_table_hachage: test_table_hachage.o table_hachage.o
table_hachage.o: table_hachage.c table_hachage.h
test_table_hachage.o: test_table_hachage.c table_hachage.h
