.data
xi:	.long 0xaabbccdd, xi, -4500
xb:	.byte 0x3f, 35, 'c'
message: .asciz  "Hello World"
	.lcomm tab1, 10
	.lcomm tab2, 10
.text
	.globl main
main:	pushl %ebp
