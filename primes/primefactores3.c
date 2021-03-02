# include <stdio.h> 
# include <math.h>
#define MAXNMUM 100
#define MINNUM 2
  int main(){
    int n, k, i, count;
    count =0;
    for ( k = MINNUM; k <= MAXNMUM; k++ ){
        n=k;
    while (n%2 == 0) { 
        n = n/2; 
        count++;
    } 
    for ( i = 3; i * i <=n; i = i+2) { 
        while (n%i == 0) { 
            n = n/i;
            count++; 
        } 
    } 
    if (n > 2) {
        count++;
    }
    }
    printf ("%d ", count);
} 
  

 