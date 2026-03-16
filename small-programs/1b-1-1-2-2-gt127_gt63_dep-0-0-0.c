#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	unsigned char x;
	unsigned char c = argv[1][0];
	
	if (c > 127)
		x = c / 3;
	else
		x = c * 2;
	
	if (x > 63)
		printf("if-2-win\n");
	else
		printf("if-2-lose\n");
	
	return 0;
}
