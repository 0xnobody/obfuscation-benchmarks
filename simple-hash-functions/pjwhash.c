#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "../annotations.h"

unsigned int POLARIS_ANNOTATE PJWHash(char* str, unsigned int len)
{
   BACKEND_OBFU;
   const unsigned int BitsInUnsignedInt = (unsigned int)(sizeof(unsigned int) * 8);
   const unsigned int ThreeQuarters     = (unsigned int)((BitsInUnsignedInt  * 3) / 4);
   const unsigned int OneEighth         = (unsigned int)(BitsInUnsignedInt / 8);
   const unsigned int HighBits          = (unsigned int)(0xFFFFFFFF) << (BitsInUnsignedInt - OneEighth);
   unsigned int hash              = 0;
   unsigned int test              = 0;
   unsigned int i                 = 0;

   for(i = 0; i < len; str++, i++)
   {
      hash = (hash << OneEighth) + (*str);

      if((test = hash & HighBits)  != 0)
      {
         hash = (( hash ^ (test >> ThreeQuarters)) & (~HighBits));
      }
   }

   return hash;
}
/* End Of  P. J. Weinberger Hash Function */

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  unsigned char *str = argv[1];
  
  unsigned int hash = PJWHash(str, strlen(str));
  
  //printf("%x\n", hash);
  
  if (hash == 0xaf9bec9)
		printf("You win!\n");
  return 0;
}

