#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_DICEQ_LEN 2
#define MAX_SIDES_LEN 4

/* prototypes */
int validate_dice_args(char *s1, char *s2);
void roll(char *arg_str1, char *arg_str2);
void usage(void);

int main(int argc, char **argv) {
	char *dice_q;
	char *dice_sides;

	/* TODO: can we validate args better than we already are? */
	switch(argc) {
		case 2:
			/* handle inputs like 1d20, 2d6, etc */
			dice_q = strtok(argv[1], "d");
			dice_sides = strtok(NULL, "\0");

			if(!validate_dice_args(dice_q, dice_sides))
				return 1;

			roll(dice_q, dice_sides);
			break;
		case 3:
			/* handle inputs like 1 20, 2 6, etc */
			if(!validate_dice_args(argv[1], argv[2]))
				return 1;

			roll(argv[1], argv[2]);
			break;
		default:
			printf("Invalid arguments.\n");
			usage();
			return 1;
			break;
	}


	return 0;
}

int validate_dice_args(char *s1, char *s2) {
	if(strlen(s1) > MAX_DICEQ_LEN)
	{
		printf("Invalid dice quantity: %s\n", s1);
		usage();
		return 0;
	}
	else if(strlen(s2) > MAX_SIDES_LEN)
	{
		printf("Invalid dice sides: %s\n", s2);
		usage();
		return 0;
	}
	else
	{
		return 1;
	}
}

void roll(char *arg_str1, char *arg_str2) {
	int i, dice_q, dice_sides;
	/* random seed */
	time_t t;
	srand((unsigned) time(&t));

	dice_q = atoi(arg_str1);
	dice_sides = atoi(arg_str2);

	for(i = 1; i <= dice_q; i++)
	{
		/* rand w/ min and max:
		 * (rand() % (max + 1 - min) + min)
		 */
		printf("%2d:  Rolled a %4d!", i, (rand() % (dice_sides + 1 - 1) + 1));

		if(dice_q < 10 || i % 2 == 0)
		{
			printf("\n");
		}
		else
		{
			printf("    ");
		}
		if(i == dice_q && dice_q >= 10 && i % 2 != 0)
		{
			printf("\n");
		}
	}
}

void usage(void) {
	printf("dice - Roll x dice with y sides.\n");
	printf("       Usage:\n");
	printf("         dice XDICE YSIDES\n");
	printf("      or dice XDICEdYSIDES\n");
	printf("         Example - roll 2x 6-sided dice:\n");
	printf("         dice 2 6\n");
	printf("         dice 2d6\n");
	printf("\n");
}
