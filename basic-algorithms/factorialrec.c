#include<stdio.h>
#include "../annotations.h"
int fact(int);
int POLARIS_ANNOTATE main(int argc, char* argv[]) {
  BACKEND_OBFU;
  if(argc < 2) return 1;
  int num,f;
//  printf("\nEnter a number: ");
//  scanf("%d",&num);
  num = (int) argv[1][0];//4;
  f=fact(num);
  printf("\nFactorial of %d is: %d\n",num,f);
  return 0;
}

int POLARIS_ANNOTATE fact(int n) {
   BACKEND_OBFU;
   if(n==1)
       return 1;
   else
       return(n*fact(n-1));
 }
