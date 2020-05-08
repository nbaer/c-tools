CC=cc
CFLAGS=-std=iso9899:1999 -Wall -g -fno-builtin -pedantic -pedantic-errors -O0

all:
	mkdir -p bin
	$(CC) $(CFLAGS) src/type_ref.c -o bin/type_ref

clean:
	rm bin/type_ref*
	rmdir bin
