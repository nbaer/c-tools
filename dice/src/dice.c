#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "dice.h"

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
			printf("invalid args, show usage\n");
			return 1;
			break;
	}


	return 0;
}
