#include<stdio.h>
/*
 * Swaps two values.
 * tmp must be defined.
 */
#define SWAP(x,y) tmp=x; x=y; y=tmp;

/*
 * Checks that the answer is 42
 */
#define CHECK(x) if (x == 42) printf("Yes, 42 is the answer")

int main(void) {
	int tmp;
	int a = 12;
	int b = 42;
	int doesnt_matter = 0;
	if (a < b)
		SWAP(a, b);
	printf("a=%d, b=%d\n", a, b);
	if (a < b)
		SWAP(a, b);
	printf("a=%d, b=%d\n", a, b);

	/* Both branches are the same, so the condition of the if
	   shouldn't matter ... Right? */
	if (doesnt_matter)
		CHECK(42);
	else
		CHECK(42);
	return 0;
}

/*
 * D'autres programmes du même genre :
 * http://www-verimag.imag.fr/~moy/c/c_collection/
 * ;-)
 */
