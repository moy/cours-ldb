CFLAGS=-Wall -Wextra -Werror -g -ansi -pedantic -std=c99
ASFLAGS=-g

all: test_c test_asm
run: all
	./test_c > test_c.out
	@cat test_c.out
	./test_asm > test_asm.out
	diff -u test_c.out test_asm.out

test.o unrolled_list.o unrolled_list_c.o: unrolled_list.h

test_c: test.o unrolled_list.o unrolled_list_c.o
	gcc $^  -o $@
test_asm: test.o unrolled_list.o unrolled_list_asm.o
	gcc $^  -o $@

clean:
	-$(RM) *.o test_c
