# include <stdio.h> 
# include <math.h>
#define MAXNUM 100
#define MINNUM 2
  int main(){
    int n, count,prime,j,k,i;
    count=0;
    for ( k = MINNUM; k<MAXNUM; k++) {
         n=k;
        prime =1;
        j=2;
        while (j <= n - 1 && prime == 1){
             if (n % j == 0){
               count++;
                 prime = 0; 
                 }   
             if (prime==1) {              
        while (n%2 == 0) {  
              n = n/2; 
              count++;
               } 
        for ( i = 3; i * i <=n; i = i+2) { 
            while (n%i == 0) { 
                 count++; 
                 n = n/i; 
                   } 
              } 
           } 
            j++; 
        }
        if (n==2)
           count++;
     }
   printf ("%d ", count); 
  }