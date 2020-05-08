#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double k, p;

	switch(argc) {
		case 2:
			break;
		default:
			printf("Usage: %s <value to convert to pounds>\n", argv[0]);
			printf("Too many or too few arguments\n");
			return 1;
			break;
	}

	k = atof(argv[1]);
	p = k * 2.2046;

	printf("%.4fkg | %.4flbs\n", k, p);

	return 0;
}
