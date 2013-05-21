#ifdef __APPLE__
#define printf _printf
#define scanf _scanf
#define main _main
#endif

.text
calcule_age:
    pushl %ebp
    movl %esp, %ebp
    // Pas de variable locale

    movl $2013, %eax
    subl 8(%ebp), %eax

    leave
    ret

    .globl main
main:
    pushl %ebp
    movl %esp, %ebp
    // de la place pour :
    // 2 variables locales => 8 octets
    subl $8, %esp

    // Corps de main()

    // printf("Annee de naissance ? ");
    pushl $fmt_annee
    call printf
    addl $4, %esp

    // scanf("%u", &annee);
    movl %ebp, %eax
    addl $-4, %eax
    pushl %eax
    pushl $fmt_u
    call scanf
    addl $8, %esp

    // age = calcule_age(annee)
    pushl -4(%ebp)
    call calcule_age
    addl $4, %esp
    // Valeur de retour
    // dans %eax
    movl %eax, -8(%ebp)

    pushl -8(%ebp)
    pushl $fmt_age
    call printf
    addl $8, %esp
    
    leave
    ret

.data
fmt_annee: .asciz "Annee de naissance ? "
fmt_age:   .asciz "Age : %u ans.\n"
fmt_u:     .asciz "%u"
