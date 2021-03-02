#include<stdio.h>
#include<math.h>

int main()
{long i, j;
 double sum, curent, s3;
 i=1;
 j=3;
 do
   {
     curent= (1/((double)i)) - (1/((double)j));
     sum = sum+curent;
     i = i+4;
     j = j+4;
   } while (curent > 1.0e-15);
   s3 = sum;
   printf("Summed %8ld terms, s3 is %10.8f\n", i-1, s3);
 }