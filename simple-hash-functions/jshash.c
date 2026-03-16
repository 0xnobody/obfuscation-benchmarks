#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

unsigned int POLARIS_ANNOTATE JSHash(char* str, unsigned int len)
{
   BACKEND_OBFU;
   unsigned int hash = 1315423911;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash ^= ((hash << 5) + (*str) + (hash >> 2));
   }

   return hash;
}
/* End Of JS Hash Function */

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  unsigned char *str = argv[1];
  
  unsigned int hash = JSHash(str, strlen(str));
  
  //printf("%x\n", hash);
  
  if (hash == 0x120bdadd)
		printf("You win!\n");
  return 0;
}

