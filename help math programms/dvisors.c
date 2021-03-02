#include <stdio.h>
#define MINNUM 2000000
#define MAXINUM 3000000

int main(){
    int n, divisor, count;
    for (n= MINNUM ; n<= MAXINUM ; n++ ) {
        count =2;
        for (divisor = 2 ; divisor * divisor <n ; divisor++) {   
           if (n % divisor ==0){
            count += 2;
            }
        
    
         if  ( n == divisor  * divisor){
              count++; 
          }
        }  
    }
    printf ("Number of divisors of %d is %d\n", n, count ); 
}
 