#ifdef __APPLE__
#define main _main
#endif

.text
.global main
main:	
	movl $0x12345678, %ebx
	movl 0x12345678, %ebx
	movl main, %ebx
	movl 0, %ebx
	movl $main, %ebx
	movl 0x12345678, %ecx
