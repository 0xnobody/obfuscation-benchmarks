#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	int i;
	int sum = 0;
	
	for (i = 0; i < argc; i++) {
		if (argv[i][0] > 127) {
			sum += 1;
		}
	
		sum += i; 
	}
	
	printf("Sum is: %d\n", sum);
	
	return 0;
}
