CC=cc
CFLAGS=-std=iso9899:1999 -Wall -g -fno-builtin -pedantic -pedantic-errors -O0

temp:
	mkdir -p bin
	$(CC) $(CFLAGS) src/ferenheit_to_celsius.c -o bin/f2c
	$(CC) $(CFLAGS) src/celsius_to_ferenheit.c -o bin/c2f

weight:
	mkdir -p bin
	$(CC) $(CFLAGS) src/kilograms_to_pounds.c -o bin/kg2lb
	$(CC) $(CFLAGS) src/pounds_to_kilograms.c -o bin/lb2kg

all:
	make temp
	make weight

clean:
	rm -f bin/c2f*
	rm -f bin/f2c*
	rm -f bin/kg2lb*
	rm -f bin/lb2kg*
	rmdir bin
