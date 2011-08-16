#ifndef LISTE_H
#define LISTE_H

typedef struct _liste liste;

/* Cree une liste chainee d'entiers signes */
extern liste* init_liste();

/* Renvoie 0 ssi la liste n'est pas vide */
extern int est_vide(const liste* const l);

/* Affiche le contenu de la liste */
extern void affiche(const liste* const l);

/* Insere un element en tete de liste, cout constant (% malloc) */
extern void insere_tete(int v,
			liste* const l);

/* Insere un element en queue de liste, cout constant (% malloc) */
extern void insere_queue(int v,
			 const liste* const l);

/* Renvoie 0 ssi l'entier v n'est pas dans la liste */
extern int recherche(int v,
		     liste* const l);

/* Applique la fonction fct a chaque element de la liste */
extern int parcours(void (*fct)(int*),
		    const liste* const l);

/*
 * Supprime la premiere occurence de l'entier v dans la liste
 *  (ne fait rien si la liste est vide ou si v n'est pas dans la liste)
 */
extern void supprime_element(int v,
			     liste* const l);

#endif /* LISTE_H */
