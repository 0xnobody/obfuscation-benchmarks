#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

unsigned int POLARIS_ANNOTATE RSHash(char* str, unsigned int len)
{
   BACKEND_OBFU;
   unsigned int b    = 378551;
   unsigned int a    = 63689;
   unsigned int hash = 0;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = hash * a + (*str);
      a    = a * b;
   }

   return hash;
}
/* End Of RS Hash Function */

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  unsigned char *str = argv[1];
  
  unsigned int hash = RSHash(str, strlen(str));
  
  //printf("%x\n", hash);
  
  if (hash == 0x4d248f4a)
		printf("You win!\n");
  return 0;
}

