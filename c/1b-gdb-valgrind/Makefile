all: c-et-compilation.pdf hello.exe

doc: c-et-compilation.pdf

include LaTeX.mk

hello.exe: hello.c
	gcc -Wall -Wextra -g $< -o $@

.PHONY: force all doc
force:
