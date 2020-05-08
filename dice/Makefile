CC=cc
CFLAGS=-std=iso9899:1999 -Wall -g -fno-builtin -pedantic -pedantic-errors -O0

all:
	mkdir -p bin
	$(CC) $(CFLAGS) src/dice.c src/dice_handle.c -o bin/dice
	$(CC) $(CFLAGS) src/dice_singlefile.c -o bin/dice_singlefile

clean:
	rm -f bin/dice*
	rmdir bin
