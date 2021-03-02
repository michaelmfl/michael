#include <stdio.h>
#include <math.h>
#define MAXNUM 1000
#define MINMUM 2
int main()
{int  i, count, divisor, prime;
  count = 0;
   for (i = MINMUM; i < MAXNUM; i++){
     prime =1;
     if (i != 2 && i% 2==0){
        prime =0;
      }
      else if (i !=3 && i % 3 == 0){
        prime=0;
      }
      else{
        divisor =5;
        while (prime == 1 && divisor * divisor <= i){
          if (i% divisor == 0 || i % (divisor + 2) == 0){
            prime = 0;
          }
          divisor +=6;
        }
      }
      if (prime ==1){
        count ++;
      }  
   }    
   printf(" found %d prime numbers up to %d", count, MAXNUM);
}


       

    

 

