#ifndef _DICE_H_
#define _DICE_H_

#define MAX_DICEQ_LEN 2
#define MAX_SIDES_LEN 4

/* prototypes */
int validate_dice_args(char *s1, char *s2);
void roll(char *arg_str1, char *arg_str2);
void usage(void);

#endif
