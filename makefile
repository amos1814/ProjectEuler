%: %.c
	gcc $*.c -Wall -lgmp -o $* -03