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
	// ...
        movl $0, %eax
        leave
        ret
