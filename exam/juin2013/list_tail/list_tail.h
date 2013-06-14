/********************************************************************
 * Copyright (C) 2013 by Verimag                                    *
 * Initial author: Matthieu Moy                                     *
 ********************************************************************/

#ifndef LIST_TAIL_H
#define LIST_TAIL_H

#include <stdlib.h>

struct cell;

struct list {
	struct cell *first;
	struct cell *last;
};

struct cell {
	struct cell *next;
	char val;
};

/*
  Appelle la fonction f sur chaque caractère de la chaîne. À chaque
  appel, la fonction f reçoit le caractère, passé par adresse, en
  premier argument, et la valeur arg.

  f peut bien sûr choisir d'ignorer l'un des arguments.
*/
extern void list_iterate(struct list *s,
			 void (*f)(char *, void *),
			 void *arg);

/*
  Concatène src et dest. Le résultat est stoké dans dest, et la liste
  pointée par src est détruite (la mémoire anciennement occupée par
  src et qui n'est pas utilisée dans le résultat est libérée).
*/
extern void list_cat(struct list *dest, struct list *src);

/*
  Ajoute le caractère c à la liste l.
*/
extern void list_append(struct list *s, char c);

/*
  Renvoie une liste contenant les caractères de la chaine content.
*/
extern struct list *list_new(char *content);

/*
  Passe tous les caractères de la liste s en majuscule.
*/
extern void list_to_upper(struct list *s);

/*
  Libère la mémoire occupée par la liste s (toute la mémoire, y
  compris les cellules de la liste.
*/
extern void list_free(struct list *s);

/*** Exclus de la doc ***/

/*
  Calcule la taille (nombre de caractères) de la liste s.
*/
extern size_t list_len(struct list *s);
extern size_t list_len_iter(struct list *s); // Idem, en utilisant list_iterate

/*
  Affiche les caractères contenus dans la liste s.
*/
extern void list_print(struct list *s);
extern void list_print_iter(struct list *s); // Idem en utilisant list_iterate
extern void list_print_opt(struct list *s); // Idem, en version optimisée

#endif // LIST_TAIL_H
