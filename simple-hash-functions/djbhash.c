#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

unsigned int POLARIS_ANNOTATE DJBHash(char* str, unsigned int len)
{
   BACKEND_OBFU;
   unsigned int hash = 5381;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = ((hash << 5) + hash) + (*str);
   }

   return hash;
}
/* End Of DJB Hash Function */

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  unsigned char *str = argv[1];
  
  unsigned int hash = DJBHash(str, strlen(str));
  
  //printf("%x\n", hash);
  
  if (hash == 0x49a54935)
		printf("You win!\n");
  return 0;
}

