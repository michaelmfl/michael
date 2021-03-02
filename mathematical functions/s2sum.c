#include<stdio.h>
#include<math.h>

int main()
{long i, j;
double sum, curent, s2;
  i=1;
  j=2;
  sum=0.0;
      do{ 
         curent = (1/((double)i))- (1/((double) j));
         sum = sum + curent;
         i = i+2;
         j = j+2; 
       } while (curent > 1.0e-15);
       s2 = sum;
  printf("Summed %8ld terms, s2 is %10.8f\n", i-1, s2);
}