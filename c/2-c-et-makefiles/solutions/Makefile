.PHONY: clean real-clean all

CC      = gcc
CFLAGS  = -Werror -Wextra -Wall -pedantic -ansi -g -std=c99

LD      = gcc
LDFLAGS =

BIN     = moyenne_liste

OBJS    =\
	liste.o\
	stats.o\
	stats_listes.o\
	moyenne_liste.o

# Facultative, mais traditionnellement, la premiere cible d'un
# Makefile (qui est aussi celle par defaut) est "all". Si on a un
# doute, on peut faire "make all".
all: $(BIN)

$(BIN): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $^

# la dependance %.o: %.c est dans la regle generique d'en dessous.
stats_listes.o: stats.h liste.h
moyenne_liste.o: stats.h liste.h stats_listes.h
stats.o: stats.h

%.o: %.c
	$(CC) $(CFLAGS) -c $<

clean:
	-$(RM) *.o

real-clean: clean
	-$(RM) $(BIN)
