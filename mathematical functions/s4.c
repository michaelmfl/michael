/*file: sums4.c*/
#include <stdio.h>
#include <math.h>
int main()
{ long i, j;
double sum, current, s4;
  i = 1;
  j = 3;
  sum = 0.0;
  do{
      current = 1/(((double) i) * ((double) j));
      sum = sum+current;
      i = i+2;
      j = j+2;
    }while (current > 1.0e-15);
    s4 = sum;
    printf("Summed %8ld terms, s4 is %10.8f\n", i-1, s4);
return 0;
}