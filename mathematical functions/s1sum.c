/* File:sisum.c */
#include <stdio.h>
#include <math.h>
int main ()
{ long i, j;
  double sum, current, s1;
  i = 1;
  j = 2;
  sum = 0.0;
  do {
      current = (1/(((double) i) * ((double) i))) - (1/(((double)j)*((double)j)));
      sum = sum+current;
      i = i+2;
      j = j+2;
  }while (current > 1.0e-8);
  s1 = sum;
  printf("Summed %8ld terms, s1 is %10.8f\n", i-1, s1);
return 0;
}