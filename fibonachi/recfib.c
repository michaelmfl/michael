#include <stdio.h>
#include "getinteger.h"


int recfib (int n){
    int i, x, y, z;
    if (n == 0)
        return 0;
    if (n == 1)
           return 1;
    x = 0;
    y = 1;
    for ( i = 2 ; i <= n ; i++){
        z = x + y;
        x = y;
        y = z;
    }
    return z;
}

int main (void){
    int i, n ;
    n = getinteger(10);
    for(i = 0 ; i <= n ; i++)
       printf ("fib (%d) = %d\n", i, recfib(i));
    return 0;
}