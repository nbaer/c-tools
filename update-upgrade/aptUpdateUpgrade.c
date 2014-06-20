/*
 * aptUpdateUpgrade.c
 *
 * 
 * This program runs "apt-get update && apt-get upgrade".
 * It takes 1 optional argument: the local username.
 *	If this argument is "root", sudo is not used.
 *	If the argument is not passed or anything but "root",
 *		sudo is used.
 *
 * Written by: nbaer on 6/18/2014
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
	char command[50];
	char go;

	if(argc > 1 && argv[1] == "root") {
		strcpy(command, "apt-get update && apt-get upgrade");
		printf("[aptupup] Update and Upgrade without using sudo? [y/N] ");
	} else {
		strcpy(command, "sudo apt-get update && sudo apt-get upgrade");
		printf("[aptupup] Update and Upgrade using sudo? [y/N] ");
	}

	go = getchar();

	switch(go) {
		case 'y':
		case 'Y':
			system(command);
			return 0;
		case 'n':
		case 'N':
			printf("Exit!\n");
			return 0;
		default:
			printf("[aptupup] Invalid input. Exiting.\n");
			return 1;
	}
}
