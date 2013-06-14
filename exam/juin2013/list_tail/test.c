/* Programme de test qui affiche :

hello, world!
len = 14
hello, world!
hello, world!
 */

#include "list_tail.h"
#include <stdio.h>

int main() {
	struct list *l1 = list_new("hello");
	struct list *l2 = list_new(",");
	list_cat(l1, l2);
	list_append(l1, ' ');
	list_cat(l1, list_new("world\n"));
	list_print(l1);
	list_to_upper(l1);
	list_print_iter(l1);
	printf("len = %d\n", list_len(l1));
	printf("len_iter = %d\n", list_len_iter(l1));

	struct list *empty = list_new("");
	struct list *empty2 = list_new("");
	list_cat(empty, empty2);
	list_to_upper(empty);
	list_print_iter(empty);
	list_append(empty, 'x');
	printf("x="); list_print(empty); printf("\n");
	list_cat(empty, list_new(""));
	list_cat(empty, list_new(""));
	list_cat(empty, list_new(""));
	printf("x="); list_print(empty); printf("\n");
	printf("\n");
	printf("len = %d\n", list_len(empty));

	list_free(l1);
	list_free(empty);
	return 0;
}
