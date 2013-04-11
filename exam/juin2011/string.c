#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct string {
        /* Les caracteres de la chaine */
        char *chars;
        /* Nombre de caracteres de la chaine */
        size_t size;
};

void create_string (struct string *str, char *val) {
        size_t size = strlen(val);
        str->size = size;
        str->chars = malloc(size);
        memcpy(str->chars, val, size);
};

void delete_string (struct string v) {
        free(v.chars);
}

size_t string_length_asm (struct string v);
size_t string_length (struct string v) {
        return v.size;
}

char *c_string_asm (struct string v);
char *c_string (struct string v) {
        char *res = malloc(v.size + 1);
        memcpy(res, v.chars, v.size);
        res[v.size] = '\0';
        return res;
}

void print_string_ext_asm(struct string v);
void print_string_ext(struct string v) {
        char *cstr = c_string(v);
        printf("%s", cstr);
        free(cstr);
}

void print_string_asm(struct string v);
void print_string_asm_opt(struct string v);
void print_string(struct string v) {
	int i;
	for (i = 0; i < v.size; i++) {
		printf("%c", v.chars[i]);
	}
}

struct string *string_concat_asm(struct string v1, struct string v2);
struct string *string_concat(struct string v1, struct string v2) {
        struct string *res = malloc(sizeof(struct string));
        res->size = v1.size + v2.size;
        res->chars = malloc(res->size);
        memcpy(res->chars, v1.chars, v1.size);
        memcpy(res->chars + v1.size, v2.chars, v2.size);
        return res;
};

int main(void) {
        struct string v1, v2, *v3;
        create_string(&v1, "Hello\n");
        print_string(v1);
        print_string_ext(v1);
        printf("size=%d\n", string_length(v1));

        create_string_asm(&v2, "world\n");
	printf("print_string         : "); print_string(v2);
        printf("print_string_asm     : "); print_string_asm(v2);
        printf("print_string_asm_opt : "); print_string_asm_opt(v2);
        printf("size=%d\n", string_length_asm(v2));

        printf("string_concat:\n");
        v3 = string_concat(v1, v2);
        print_string_asm(*v3);
	delete_string(*v3);
	free(v3);

	printf("string_concat_asm:\n");
        v3 = string_concat_asm(v1, v2);
        print_string_asm(*v3);

        delete_string(v1);
        delete_string_asm(v2);
        delete_string_asm(*v3);
	free(v3);
        return 0;
}

