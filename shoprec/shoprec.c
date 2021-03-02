#include <stdio.h>

int min(int ,int , int *, int **,int , int );

int shop(int m, int n, int *k, int **c)
{
    int s,p,i;
    p=m;              
    i=0;
    s=m-min( m, n, k, c,p,i); //καλεί την συνάρτηση min και αφαιρεί το αυτό που επιστρέφει απο τα ήδη χρήματα που έχει και τα επιστρέφει στην main,όπου και εκτυπώνεται
    return s;
}

int min(int m,int n, int *k, int **c,int p,int i)
{
    int j,a,b,x,y;   
    y=m+1;                      
    if (i==n && p>=0) {          
        return p;
    }
    else if (p<0){
        return m;
    }
    else {
        for (j=0; j<k[i]; j++){           //βρισκόμαστε στην πρώτη περίπτωση της συνάρτησης,όπου γίνεται και η αναδρομή 
            a=p-c[i][j];                  //κρατάμε το υπόλοιπο των χρημάτων αν γίνει η αγορά 
            b=i+1;                        //αυξάνουμε το προιόν κατά 1 
            x=min( m, n, k, c, a, b);     //καλούμε την ίδια συνάρτηση
            if (x<y)                      //βρίσκουμε το μικρότερο αποτέλεσμα που επιστρέφει η min
            {
                y=x;
            }
        }
    }
    return y;                             //και το επιστρέφουμε
}