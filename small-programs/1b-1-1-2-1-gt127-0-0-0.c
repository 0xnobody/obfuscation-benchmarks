#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	if (argc < 2) {
		printf("Usage: program-name argument\n");
		return 1;
	}
	
	unsigned char c = argv[1][0];
	if (c > 127)
		printf("win\n");
	else
		printf("lose\n");
	
	return 0;
}
