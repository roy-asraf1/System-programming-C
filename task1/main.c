#include <stdio.h>
#include "NumClass.h"
int main(){
    
int n1 =0, n2 = 0;
 scanf("%d%d", &n1, &n2);

printf("The Armstrong numbers are:");
  for (int i = n1; i <= n2; i++){
     if (isArmstrong(i) == 1){
        printf(" %d", i);
      }
    }
printf("\n");
printf("The Palindromes are:");
for (int i = n1; i <= n2; i++){
    if (isPalindrome(i) == 1){
                printf(" %d", i);
            }
    }
printf("\n");
printf("The Prime numbers are:");
for (int i = n1; i <= n2; i++){
    if (isPrime(i) == 1){
             printf(" %d", i);
            }
    }
printf("\n");  
printf("The Strong numbers are:");
for (int i = n1; i <= n2; i++) {
     if (isStrong(i) == 1){
                printf(" %d", i);
            }
    }
printf("\n");
return 0;

}
