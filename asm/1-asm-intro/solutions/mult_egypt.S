#ifdef __APPLE__
#define main _main
#endif

/*
int main() {
   unsigned x, y, r;
   r = 0; x = 5; y = 4;
   while (y != 0) {
      if (y % 2 == 1) {
         r += x;
      }
      x <<= 1;
      y >>= 1;
   }
   return 0;
}
*/
	
        .text
        .globl main
main:
        enter $0, $0
	/* START CUT */
        /* x : %edx, y : %ecx, r : %eax */
        xorl %eax, %eax
        movl $5, %edx
        movl $4, %ecx
main_while:
        jecxz main_while_fin
        testl $1, %ecx
        jz main_fin_if
        addl %edx, %eax
main_fin_if:
        shll $1, %edx
        shrl $1, %ecx
        jmp main_while
main_while_fin:
        /* ici le resultat (20) est dans %eax */
	/* END CUT */
	// ...
        movl $0, %eax
        leave
        ret
