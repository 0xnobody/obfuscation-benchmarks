#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include "../annotations.h"

int POLARIS_ANNOTATE fib(int n) {
   BACKEND_OBFU;
   int a = 1;
   int b = 1;
   int i;
   for (i = 3; i <= n; i++) {
      int c = a + b;
      a = b;
      b = c;
   };
   return b;
}

int POLARIS_ANNOTATE main(int argc, char* argv[]) {
    BACKEND_OBFU;
    if (argc < 2) return 1;
//  if (argc != 2) {
//     printf("Give one argument!\n");
//     abort();
//  };
//  long n = strtol(argv[1],NULL,10);
  time_t t;
  srand((unsigned) time(&t)); // seed rand()
  int n = (int) argv[1][0];//4;//rand() % 10;
  int f = fib(n);
  printf("fib(%li)=%i\n",n,f);
}
