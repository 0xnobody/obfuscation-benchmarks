#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	if (argc < 2) {
		printf("Usage: program-name argument\n");
		return 1;
	}
	
	return 0;
}
