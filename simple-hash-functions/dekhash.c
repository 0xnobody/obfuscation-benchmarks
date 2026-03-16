#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

unsigned int POLARIS_ANNOTATE DEKHash(char* str, unsigned int len)
{
   BACKEND_OBFU;
   unsigned int hash = len;
   unsigned int i    = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = ((hash << 5) ^ (hash >> 27)) ^ (*str);
   }
   return hash;
}
/* End Of DEK Hash Function */

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  unsigned char *str = argv[1];
  
  unsigned int hash = DEKHash(str, strlen(str));
  
  //printf("%x\n", hash);
  
  if (hash == 0xde4363b7)
		printf("You win!\n");
  return 0;
}

