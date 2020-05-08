#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double c, f;

	switch(argc) {
		case 2:
			break;
		default:
			printf("Usage: %s <value to convert to Ferenheit>\n", argv[0]);
			printf("Too many or too few arguments\n");
			return 1;
			break;
	}

	c = atof(argv[1]);
	f = (c * 1.80) + 32.00;

	printf("%.2fC | %.2fF\n", c, f);

	return 0;
}
