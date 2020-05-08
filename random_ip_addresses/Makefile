CC=cc
CFLAGS=-std=iso9899:1999 -Wall -g -fno-builtin -pedantic -pedantic-errors -O0

random_ip:
	mkdir -p bin
	$(CC) $(CFLAGS) src/random_ip_addresses.c -o bin/rand_ip

clean:
	rm -f bin/rand_ip*
	rmdir bin

