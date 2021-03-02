#include <stdio.h>
#include <math.h>
int main()
{long a, b, k, l, i, j;
 double  sum,current,s5;
 i=2;
 a=3;
 b=4;
 j=4;
 k=5;
 l=6;
  sum=0.0;
     do{
    current=(1/(((double)i)*((double)a)*((double)b))) - (1/(((double)j)*((double)k)*((double)l)));
       sum=sum+current;
       i=i+4;
       j=j+4;
       a=a+4;
       b=b+4;
       k=k+4;
       l=l+4;
     } while (current > 1.0e-15);
     s5=sum;
     printf("Summed %8ld terms, s5 is %10.8f\n", i-1, s5);
     return 0;
}