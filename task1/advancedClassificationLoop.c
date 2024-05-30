#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isPalindrome(int n)
{
      if (n < 0){ //valid
        return 0;
    }
    int temp = n;
    int reverse = 0;
    int rem;

    while (temp != 0){
        rem = temp % 10;
        reverse = reverse * 10 + rem;
        temp /= 10;
    }
   if(n==reverse){
       return 1;
   }
       return 0;
}

int isArmstrong(int n){
    int size=0;
    int temp=n;
    while (temp!=0) {
        size++;
        temp= temp/10;   
    }
    temp=n;
    int sum=0;
    int rem;
    while (temp!=0) {
        rem=temp%10;
        sum+=pow(rem,size);
        temp= temp/10;
    }
    if (n==sum){
        return 1;
    }
      return 0;
}






