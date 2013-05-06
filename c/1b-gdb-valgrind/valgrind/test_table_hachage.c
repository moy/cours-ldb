#include <time.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "table_hachage.h"

static int equals(void *s1, void *s2)
{
	return !strcmp((char *) s1, (char *) s2);
}

/* Tres mauvaise fonction de hachage faite expres pour trier par taille */
static unsigned hashcode(void *s)
{
	return strlen((char *) s);
}

void afficher(void *s)
{
	printf("\"%s\"", (char *) s);
}

#define NBR_CHAINES 57
static char *chaines[] = {
	"Once", "upon", "a", "midnight", "dreary",
	"while", "I", "pondered", "weak", "and",
	"weary", "Over", "many", "a", "quaint",
	"and", "curious", "volume", "of", "forgotten",
	"lore", "While", "I", "nodded", "nearly",
	"napping", "suddenly", "there", "came", "a",
	"tapping", "As", "of", "some", "one",
	"gently", "rapping", "rapping", "at", "my",
	"chamber", "door", "Tis", "some", "visitor",
	"I", "muttered", "tapping", "at", "my",
	"chamber", "door", "Only", "this", "and",
	"nothing", "more"
};

int main()
{
	unsigned i;
	table_hachage_t *t;
	srand(time(NULL));
	t = new_table_hachage(10, equals, hashcode, afficher);
	afficher_table_hachage(t);
	for (i = 0; i < NBR_CHAINES; i++) {
		inserer_table_hachage(t, chaines[i]);
	}
	afficher_table_hachage(t);
	supprimer_table_hachage(t, "pondered");
	afficher_table_hachage(t);
	supprimer_table_hachage(t, "muttered");
	afficher_table_hachage(t);
	supprimer_table_hachage(t, "midnight");
	afficher_table_hachage(t);
	supprimer_table_hachage(t, "suddenly");
	afficher_table_hachage(t);
	while (!est_vide_table_hachage(t)) {
		i = rand() % NBR_CHAINES;
		supprimer_table_hachage(t, chaines[i]);
	}
	afficher_table_hachage(t);
	detruire_table_hachage(t);
	return 0;
}
