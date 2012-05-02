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
	// ...
        movl $0, %eax
        leave
        ret

