#include <stdio.h> 
#include <stdlib.h>
#include <time.h>
#define MAXNMUM 100000
#define MINNUM  100
#define MAXK 4
#define COMPUTATIONS 20
int main() {
int n, k, i, countsemi,j,countkprime, l,x,y,z,a,p,w;
long curtime;
    curtime =time(NULL);
    countsemi =0;
    countkprime =0;
    x=0;
    y=0;
    z=0;
    w=0;
    for ( k = MINNUM; k <= MAXNMUM; k++ ){
        n=k;                                        
        j=0;
        l=0;
        while (n%2 == 0) {                  ///ακεραια  διερεση του n με το δυο 
               n = n/2;
               j++;
               if (j==1){
                  l=n;                  
                  }
              } 
    for ( i = 3; i * i <=n; i = i+2) {           //ξεχοριζω τους περιτους αριθμους για την επιταχινση του προγραμματος
        while (n%i == 0) {            
            n = n/i; 
            j++;
            if (j==1){
            l=n;
             }
              }
        }
    if (n > 2){
        j++;
        }
  if (j == 2){                                   //αν το j = 2 τοτε ο αρηθμος ειναι semiprime                                                
       countsemi++; }                            // αυτο γινετε επιδει οι semiprime numbers εχουν μονο 2 προτους παραγοντες
     if (MAXK>=j &&  2 <=j ){                     //αν το maxk=> j =>2 τοτε ο αρηθμος ειναι k almost prime
        countkprime++; }       
       if (j==2){ 
         n=k/l;                                    // ευρεση του n
         if (n!=l && l-n <((double)l)/100) {       // συνθικη για τους interesting semiprime
          
         printf("%d * %d = %d is an interesting semiprime\n", n, l, k);}
         } 
    }
    printf ("\nFound %d k-almost prime mumbers (2 <= k <= 4) \nFound %d semiprimes\n\n",countkprime, countsemi);
    srand((unsigned int)curtime);
    printf("current time is %ld\n\n", curtime);
    while (w < COMPUTATIONS){
           a=0;
           x=0;
           y = rand(); 
           z = rand();
           x = ((y % 32768) + 1) * ((z % 32768) + 1) + 1;
           p=x;
           while (x%2 == 0) {
                 x = x/2;
                 a++;
                } 
           for ( i = 3; i * i <=x; i = i+2) { 
               while (x%i == 0) {            
                      x = x/i; 
                      a++;
                     } 
                }      
           if (x > 2){
               a++;
              }
           if(a>=2){                  // αφου οι κ almost prime αρχιζουν απο κ=2 και ανω τοτε α πρεπει να ειναι2
             printf(" %d is a %d-almost prime number\n", p, a );
             w++;                       // ωστε να τυποστη  20 κ alomost prime αριθμους
             }  
                      
      }
}
