#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int i,r;
    long curtime;
    curtime = time(NULL);
    srand((unsigned int)curtime);
    printf("current time is %ld\n\n", curtime);
    for (i=0; i<20; i++){
         r = rand();
         printf("%d\n", r);
    }
    
}