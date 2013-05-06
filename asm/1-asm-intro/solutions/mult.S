#ifdef __APPLE__
#define main _main
#endif

/*
int main() {
   unsigned x, y, res;
   x = 5; y = 4; res = 0;
   for (; y != 0; y--) {
      res += x;
   }
   return 0;
}
*/

        .text
        .globl main
main:
        enter $0, $0
	/* START CUT */
        movl $4, %ecx
        movl $5, %edx
        xorl %eax, %eax 
main_while:
        jecxz main_fin_while
        addl %edx, %eax
        decl %ecx
        jmp main_while
main_fin_while:
	/* END CUT */
	// ...
        movl $0, %eax
        leave
        ret

