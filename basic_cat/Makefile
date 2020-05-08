CC=cc
CFLAGS=-std=iso9899:1999 -Wall -g -fno-builtin -pedantic -pedantic-errors -O0

all:
	mkdir -p bin
	$(CC) $(CFLAGS) src/basic_cat.c -o bin/basic_cat

clean:
	rm -f bin/basic_cat*
	rmdir bin
