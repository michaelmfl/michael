#include<stdio.h>
#define MAXNUM 100
 
int main(){

     int n, count,prime, divisor;
     count = 0;
     for (n = 2 ; n <= MAXNUM; n++){
          prime = 1;
          divisor = 2;
          while (divisor  * divisor <= n  && prime == 1){
                if (n % divisor == 0){
                    prime = 0;
             
                    }    
                divisor++;
                }
                if (prime == 1 ){
                    printf("%d is prime\n", n);
                    count++;         
                    }
                    else{
                    //printf("%d is not  prime \n", n);
                }
         }
         printf("Found %d prime numbers up to %d\n",count, MAXNUM);
}