#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dice.h"

int validate_dice_args(char *s1, char *s2) {
	if(strlen(s1) > MAX_DICEQ_LEN)
	{
		printf("Invalid dice quantity: %s\n", s1);
		return 0;
	}
	else if(strlen(s2) > MAX_SIDES_LEN)
	{
		printf("Invalid dice sides: %s\n", s2);
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
