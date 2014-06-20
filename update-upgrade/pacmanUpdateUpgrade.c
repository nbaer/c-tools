/*
 *	This program runs "pacman -Syu" with or without sudo, based on user input.
 *
 *	Written by: Nick on 6/20/2014
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function prototypes
int verifyAction(char input);
int sudoOption(char input, char *command);
void runSys(char *command);

int main(void)
{
	// Set up the buffer and "switch" variables
	char command[50];
	char verify;
	char sudo;

	// Confirm update/upgrade
	printf("[pacupup] Update repos and upgrade the system using pacman? [y/N] [default: N] ");
	verify = verifyAction(getchar());

	if(verify > 0) {
		// Prompt for usage of sudo
		printf("[pacupup] Use sudo? [y/N] [default: y] ");
		sudo = sudoOption(getchar(), command);

		if(sudo > 0) {
			// Run the command using system()
			runSys(command);
		} else {
			return 1;
		}
	}

	return 0;
}

int verifyAction(char input)
{
	int ch;


	switch(input) {
		case 'n':
		case 'N':
		case '\n':
			printf("[pacupup] Exiting.\n");
			return 0;
		case 'y':
		case 'Y':
			// Eat any extra input and \n
			while((ch = getchar()) != '\n' && ch != EOF);
			return 1;
		default:
			printf("[pacupup] Invalid input. Exiting.\n");
			return 0;
	}
}

int sudoOption(char input, char *command)
{
	switch(input) {
		case '\n':
		case 'y':
		case 'Y':
			// Prepare the command line string
			strcpy(command, "sudo pacman -Syu");
			return 2;
		case 'n':
		case 'N':
			// Prepare the command line string
			strcpy(command, "pacman -Syu");
			return 1;
		default:
			// The user started their input string with something other than y, Y, n, N, or \n; ABORT
			printf("[pacupup] Invalid input. Exiting.\n");
			return 0;
	}
}

void runSys(char *command)
{
	// Run the command using system()
	system(command);
}
