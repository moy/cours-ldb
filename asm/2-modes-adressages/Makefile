SOL=${wildcard solutions/*.S}
SQUEL=$(SOL:solutions/%.S=%.S)

all: $(SQUEL) langage-dassemblage-syntaxe.pdf

%.S: solutions/%.S
	cd solutions/ && generer-squelette.pl -o ../ $*.S 

%.pdf: %.odp
	unoconv --format=pdf --stdout $< > $@

debug:
	echo $(SQUEL)
