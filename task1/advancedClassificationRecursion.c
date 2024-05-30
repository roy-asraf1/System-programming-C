#include <stdio.h>
#include <math.h>
#include "NumClass.h"

int isArmstrongHelper(int n, int size) ;
// palindrome helper
int isPalindromeHelper(int n, int temp, int reverse) {
if (temp == 0) {
     if (n == reverse) {
          return 1;
      } 
        else {
            return 0;
        }
}
int r = temp % 10;
reverse = reverse * 10 + r;
temp = temp / 10;
return isPalindromeHelper(n ,temp, reverse);
}

int isPalindrome(int n) {
    return isPalindromeHelper(n, n, 0);
}

int isArmstrong(int n) {

    if (n <= 0) // valid
    {
        if (n==0){
           return 1;
        }
        return 0;
    }
    
    int temp = n;

    int size = 0;

    while (temp > 0)
    {
        temp /= 10;

        size++;
    }

    return isArmstrongHelper(n, size) == n;  
}
//  private helper method:

int isArmstrongHelper(int n, int size) {
    if (n == 0) {
        return 0;
    }
    int r = n % 10;
    return pow(r, size) + isArmstrongHelper(n / 10, size);
}

