#
# Makefile
#
# Computer Science 50
# Problem Set 2
#

all: initials caesar vigenere

initials: initials.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o initials initials.c -lcs50 -lm

caesar: caesar.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o caesar caesar.c -lcs50 -lm

vigenere: vigenere.c
	clang -ggdb3 -O0 -std=c99 -Wall -Werror -o vigenere vigenere.c -lcs50 -lm

clean:
	rm -f *.o a.out core initials caesar vigenere
