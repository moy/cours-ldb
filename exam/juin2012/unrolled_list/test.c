/* Programme de test qui affiche :

hello, world!
len = 14
hello, world!
hello, world!
 */

#include "unrolled_list.h"
#include <stdio.h>

int main() {
	struct unrolled_list *r = unrolled_list_new("hello");
	unrolled_list_append(r, ", ");
	unrolled_list_append(r, "world!\n");
	unrolled_list_print(r);
	printf("len = %d\n", unrolled_list_len(r));
	struct unrolled_list *r2 = unrolled_list_pack(r);

	unrolled_list_print(r2);
        // Version optimisee de la meme fonction.
	unrolled_list_print_opt(r);

	unrolled_list_free(r);
	unrolled_list_free(r2);
	return 0;
}
