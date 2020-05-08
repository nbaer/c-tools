#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double c, f;

	switch(argc) {
		case 2:
			break;
		default:
			printf("Usage: %s <value to convert to Celsius>\n", argv[0]);
			printf("Too many or too few arguments\n");
			return 1;
			break;
	}

	f = atof(argv[1]);
	c = (f - 32.00) / 1.80;

	printf("%.2fF | %.2fC\n", f, c);

	return 0;
}
