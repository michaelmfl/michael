#include<stdio.h>
#define NUMBER 15
 
int main(){

     int prime, i;
     prime =1;
     i=2;
     while (i <=  NUMBER - 1 && prime == 1){
         if (NUMBER % i == 0){
             prime = 0;
             
          } 
         i++;
     }
    if (prime == 1 ){
        printf("%d is prime\n", NUMBER);
        
    }
    else{
         printf("%d is not  prime \n",NUMBER);
    }
}