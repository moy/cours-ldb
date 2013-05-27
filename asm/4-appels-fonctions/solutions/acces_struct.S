
// void affichage(struct structure_t s)
// {
.globl affichage
affichage:
	pushl %ebp
	movl %esp, %ebp

//     affiche(s.entier, s.ptr);
	pushl 12(%ebp)
	pushl 8(%ebp)
	call affiche
	addl $8, %esp
// }
	leave
	ret
// void modification(int entier, int *ptr, struct structure_t *s)
// {
param_s=16
struct_entier=0
struct_ptr=4
param_entier=8
param_ptr=12
.globl modification
modification:
	pushl %ebp
	movl %esp, %ebp
//     s->entier = entier;
	movl param_s(%ebp), %eax
	movl param_entier(%ebp), %ecx
	movl %ecx, struct_entier(%eax)
//     s->ptr = ptr;
	movl param_s(%ebp), %eax
	movl param_ptr(%ebp), %ecx
	movl %ecx, struct_ptr(%eax)
// }
	leave
	ret

