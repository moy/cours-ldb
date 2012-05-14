	.data
fmt_d:	.asciz "%d\n"
	
	.text
	.globl main
	// int main() {
main:
	pushl %ebp
	movl %esp, %ebp
	subl $4, %esp

	// int a = 42;
	movl $42, -4(%ebp)

	// increment(&a);
	movl %ebp, %eax
	addl $-4, %eax
	pushl %eax
	call increment
	addl $4, %esp

	// printf("%d\n", a);
	pushl -4(%ebp)
	pushl $fmt_d
	call printf
	addl $8, %esp

	// return 0;
	xorl %eax, %eax
	leave
	ret

	// void increment(int *x)
increment:
	pushl %ebp
	movl %esp, %ebp

	// (*x)++;
	movl 8(%ebp), %eax
	incl (%eax)

	leave
	ret
