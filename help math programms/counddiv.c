#include <stdio.h>
#define MINNUM 20000000
#define MAXNUM 21000000

int main(){
    int n, divisor,count;
    for (n = MINNUM ; n <= MAXNUM ;n++){
        count = 2;
        for (divisor = 2 ; divisor * divisor <n ; divisor++) {
            if (n % divisor == 0){
                count += 2;
            }           
        }
        if (n == divisor * divisor){
            count++;
        }
        printf("Number of divisors of % is %d\n", n, count);
    }
}