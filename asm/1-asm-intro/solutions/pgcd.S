#ifdef __APPLE__
#define main _main
#endif

/* Calcule le pgcd de deux nombres strictement positifs : ici 15 et 10. */
        .text
/*
  La directive .globl (qui s'ecrit aussi .global sous Linux) rend l'etiquette
    visible depuis l'exterieur du module.
*/
        .globl main
main:
        enter $0, $0      /* on commence une fonction par enter */
        movl $15, %ecx    /* %ecx := 15 */
        movl $10, %edx    /* %edx := 10 */
main_while:
        cmpl %ecx, %edx   /* comparaison : %edx - %ecx */
        je main_fin_while /* si %ecx = %edx, on va a main_fin_while */
/* Attention : on travaille sur des unsigned => jb et pas jl */
        jb main_else      /* si %edx < %ecx, on va a main_else */
        subl %ecx, %edx   /* %edx := %edx - %ecx */
        jmp main_fin_if   /* on va a main_fin_if */
main_else:
        subl %edx, %ecx   /* %ecx := %ecx - %edx */
main_fin_if:
        jmp main_while    /* on va a main_while */
main_fin_while:
        xorl %eax, %eax   /* on renvoie 0 au systeme ("pas d'erreur") */
        leave             /* on termine une fonction par leave et ret */
        ret               /* return */
