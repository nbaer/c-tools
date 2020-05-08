#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	double k, p;

	switch(argc) {
		case 2:
			break;
		default:
			printf("Usage: %s <value to convert to kilograms>\n", argv[0]);
			printf("Too many or too few arguments\n");
			return 1;
			break;
	}

	p = atof(argv[1]);
	k = p / 2.2046;

	printf("%.4flbs | %.4fkg\n", p, k);

	return 0;
}
