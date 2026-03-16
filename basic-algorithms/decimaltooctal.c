#include<stdio.h>
#include "../annotations.h"

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  
  if (argc < 2) return 1;
  long int decimalNumber,remainder,quotient;
  int octalNumber[100],i=1,j;

//  printf("Enter any decimal number: ");
//  scanf("%ld",&decimalNumber);
  decimalNumber = (int) argv[1][0];

  quotient = decimalNumber;

  while(quotient!=0){
      octalNumber[i++]= quotient % 8;
      quotient = quotient / 8;
  }

  printf("Equivalent octal value of decimal number %d: \n",decimalNumber);
  for(j = i -1 ;j> 0;j--)
      printf("%d",octalNumber[j]);

  return 0;
}
