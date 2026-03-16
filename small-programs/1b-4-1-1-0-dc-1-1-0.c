#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	int i;
	int sum = 0;
	
	if (argc < 2) {
		printf("Usage: program-name char\n");
		return 1;
	}
	
	for (i = 0; i < argc; i++) {
		sum += i; 
	}
	
	printf("Sum is: %d\n", sum);
	
	return 0;
}
