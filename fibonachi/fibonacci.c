#include <stdio.h>
#include "getinteger.h"

int recfib(int n)
{
   if (n == 0)
      return 0;
   else if (n == 1)
      return 1;
   else
      return recfib(n-1)+recfib(n-2);
}

int iterfib(int n)
{
   int i, x, y, z;
   if (n == 0)
      return 0;
   if (n == 1)
      return 1;
   x = 0;
   y = 1;
   for (i = 2 ; i <= n ; i++) {
      z = x + y;
      x = y;
      y = z;
   }
   return z;
}

int main(void)
{
   int i, n;
   printf("Please, give n: ");
   n = getinteger(10);
   printf("\nStart recursive? (press Enter)");
   getchar();
   printf("\nRecursive fibonacci\n");
   printf("--------------------\n");
   for (i = 0 ; i <= n ; i++)
      printf("fib(%d) = %d\n", i, recfib(i));
   printf("\nStart iterative? (press Enter)");
   getchar();
   printf("\nIterative fibonacci\n");
   printf("--------------------\n");
   for (i = 0 ; i <= n ; i++)
      printf("fib(%d) = %d\n", i, iterfib(i));
   return 0;
}