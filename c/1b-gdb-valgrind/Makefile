all: c-et-compilation.pdf hello.exe LdB-exemples-seance-3.tgz

doc: c-et-compilation.pdf

include LaTeX.mk

LdB-exemples-seance-3.tgz: force
	tar czvf $@ LdB-exemples-seance-3/ --exclude \*~ --exclude \*.o --exclude bonjour
	@echo "*** $@ created"

force:
