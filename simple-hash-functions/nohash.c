#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  if (strcmp(argv[1], "my_license_key") == 0)
    printf("You win!\n");
  return 0;
}
