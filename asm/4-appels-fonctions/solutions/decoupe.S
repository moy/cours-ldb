#ifdef __APPLE__
#define decoupe _decoupe
#endif
/*
struct cellule_t {
  int val;
  struct cellule_t *suiv;
};
*/
val = 0
suiv = 4

    .globl decoupe

    .text
    
    // struct cellule_t *decoupe(struct cellule_t *l, struct cellule_t **l1, struct cellule_t **l2)
l = 8
l1 = 12
l2 = 16
decoupe:
    enter $16, $0
    // struct cellule_t sent1
sent1 = -8
    // struct cellule_t sent2
sent2 = -16
    // *l1 = &sent1;
    leal sent1(%ebp), %eax
    movl l1(%ebp), %edx
    movl %eax, (%edx)
    // *l2 = &sent2;
    leal sent2(%ebp), %eax
    movl l2(%ebp), %edx
    movl %eax, (%edx)
    // while (l != NULL) {
while:
    cmpl $0, l(%ebp)
    je fin_while
    // if (l->val & 1 == 1) {
    movl l(%ebp), %eax
    testl $1, val(%eax)
    jz else
    // (*l1)->suiv = l;
    movl l(%ebp), %edx
    movl l1(%ebp), %eax
    movl (%eax), %eax
    movl %edx, suiv(%eax)
    // *l1 = l;
    movl l(%ebp), %edx
    movl l1(%ebp), %eax
    movl %edx, (%eax)
    // } else {
    jmp fin_if
else:
    // (*l2)->suiv = l;
    movl l(%ebp), %edx
    movl l2(%ebp), %eax
    movl (%eax), %eax
    movl %edx, suiv(%eax)
    // *l2 = l;
    movl l(%ebp), %edx
    movl l2(%ebp), %eax
    movl %edx, (%eax)
    // } // end if
fin_if:
    // l = l->suiv;
    movl l(%ebp), %eax
    movl suiv(%eax), %eax
    movl %eax, l(%ebp)
    // } // end while
    jmp while
fin_while:
    // (*l1)->suiv = NULL
    movl l1(%ebp), %eax
    movl (%eax), %eax
    movl $0, suiv(%eax)
    // (*l2)->suiv = NULL
    movl l2(%ebp), %eax
    movl (%eax), %eax
    movl $0, suiv(%eax)
    // *l1 = sent1.suiv
    movl (sent1 + suiv)(%ebp), %eax
    movl l1(%ebp), %edx
    movl %eax, (%edx)
    // *l2 = sent2.suiv
    movl (sent2 + suiv)(%ebp), %eax
    movl l2(%ebp), %edx
    movl %eax, (%edx)
    // return l;
    movl l(%ebp), %eax
    leave
    ret
