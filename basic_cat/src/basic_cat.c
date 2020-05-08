#include <stdio.h>
#include <getopt.h>

/* TODO: fix this output so that it contains
 * a "newline" character and EOF so that we can
 * use basic_cat to output a valid UTF-8 C source
 * file and then compile it. first, add entries in
 * Makefile for basic_cat_2_{cc,gcc}, then...
 * $ bin/basic_cat_cc src/basic_cat.c > src/basic_cat_2.c && make
 */

int main(int argc, char **argv) {
	int nflag = 0;
	char *file_to_read;
	int c_arg;
	FILE *fp;
	const char *mode = "r";
	unsigned int line_number;
	unsigned int total_lines;

	if(argc < 2)
	{
		printf("Specify a file to read.\n");
		return 1;
	}

	if(argc > 2)
	{
		while((c_arg = getopt(argc, argv, "n")) != -1)
		{
			switch(c_arg) {
				case 'n':
					nflag = 1;
					break;
				default:
					return 1;
			}
		}
	}

	file_to_read = argv[argc - 1];

	fp = fopen(file_to_read, mode);

	if(fp == NULL)
	{
		perror("basic_cat");
		return 1;
	}

	if(nflag)
	{
		line_number = 1;
		total_lines = 1;

		/* get the total lines in the file, move pointer to the end */
		while(!feof(fp))
		{
			if(fgetc(fp) == '\n') total_lines++;
		}

		/* reset the file pointer */
		rewind(fp);

		printf("%6u  ", line_number);
		line_number++;
	}

	while(!feof(fp))
	{
		unsigned char this_char = fgetc(fp);

		printf("%c", this_char);

		if(nflag && this_char == '\n' && line_number < total_lines)
		{
			printf("%6u  ", line_number);
			line_number++;
		}
	}

	/* close the file when done */
	fclose(fp);

	return 0;
}
