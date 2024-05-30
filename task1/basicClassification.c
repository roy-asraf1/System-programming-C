#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPrime(int n)
{
    if (n <= 0) {
            return 0;
    } 
    if (n == 1) {
            return 1;
    }
    for (int i = 2; i <=sqrt(n); ++i) {
        if (n % i == 0) {
                return 0;
        }
     }
        return 1;
    }
 // helper for isStrong method
 int fact(int x)
{
    int mul=1;
    for(int i=1;i<=x;i++){
        mul=mul*i;
    }
    return mul;
}

 int isStrong(int n)
{
    int temp=n;
    int sum=0;
    int rem;
    while (temp!=0){
        rem=temp%10;
        int factorial=fact(rem);
        temp/=10;
        sum=sum+factorial;
    }
    if(sum==n){
        return 1;
    }
     return 0;
}


