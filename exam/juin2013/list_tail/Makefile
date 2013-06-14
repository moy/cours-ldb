CFLAGS=-Wall -Wextra -Werror -g -ansi -pedantic -std=c99
ASFLAGS=-g
CMD_PREFIX = 

all: test_c test_asm

valgrind:
	$(MAKE) CMD_PREFIX='valgrind -q ' run

run: all
	$(CMD_PREFIX) ./test_c > test_c.out
	@cat test_c.out
	$(CMD_PREFIX) ./test_asm > test_asm.out
	diff -u test_c.out test_asm.out

test.o list_tail.o list_tail_c.o: list_tail.h

test_c: test.o list_tail.o list_tail_c.o
	gcc $^  -o $@
test_asm: test.o list_tail.o list_tail_asm.o
	gcc $^  -o $@

clean:
	-$(RM) *.o test_c test_asm
