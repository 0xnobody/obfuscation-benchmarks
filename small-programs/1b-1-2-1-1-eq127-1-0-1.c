#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	int i;
	int sum = 0;
	
	for (i = 0; i < argv[1][0]; i++) {
		if (argv[1][0] == 127)
			sum += i;
		else
			sum *= i; 
	}
	
	printf("Sum is: %d\n", sum);
	
	return 0;
}
