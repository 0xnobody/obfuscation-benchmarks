#include <stdio.h>
#include <stdlib.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
	BACKEND_OBFU;
	int i,j;
	int sum = 0;
	
	const char *str = argv[1];
	register const char *s, *t;

	for (t = str; *t; ++t) {
		sum += *t;
	}
	
	if (argc > 127)
		sum += *t;
	else
		sum *= *t;
			
	printf("Sum is: %d\n", sum);
	
	return 0;
}
