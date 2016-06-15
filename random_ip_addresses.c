/*
 * Output specified amount of random IP addresses.
 *
 * If using a valid arg, the first line of output will always be:
 *	Showing %d IPv4 addresses
 *
 * Usage (assuming program compiled with "-o ip"):
 * 	./ip					// 1 random address
 * 	./ip 100				// 100 random addresses
 * 	./ip 1000 > file.txt 	// 1000 addresses to file.txt
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void outputAddresses(int q);

int main(int argc, char *argv[])
{
	// default: show 1 ip address; maximum 1 million
	int quantity = 1;
	int maximum = 1000000;

	if(argc > 1)
	{
		quantity = atoi(argv[1]);

		if(quantity > maximum)
		{
			quantity = maximum;
		}
	}


	if(quantity > 0)
	{
		printf("Showing %d IPv4 addresses\n", quantity);
		outputAddresses(quantity);
	}
	else
	{
		printf("Invalid quantity arg. Exiting.\n");

		return 1;
	}

	return 0;
}

void outputAddresses(int q)
{
	int first_octet;
	int i;

	// new, pseudo-random seed
	srand((unsigned int)time(NULL));

	// output
	for(i = 1; i <= q; i++)
	{
		first_octet = rand() % 256;

		if(first_octet == 127 || first_octet == 10)
		{
			first_octet--;
		}
		else if(first_octet == 0)
		{
			first_octet++;
		}

		printf(
			"%d.%d.%d.%d\n",
			first_octet, rand() % 256,
			rand() % 256, rand() % 256
		);
	}
}
