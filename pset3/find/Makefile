#
# Makefile
#
# Computer Science 50
# Problem Set 3
#

all: find generate

find: find.c helpers.c helpers.h
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o find find.c helpers.c -lcs50 -lm

generate: generate.c
	gcc -ggdb -std=c99 -Wall -Werror -Wformat=0 -o generate generate.c

clean:
	rm -f *.o a.out core find generate
