#include <stdio.h>
#include <stdlib.h>
# define SIZE 50
/**
 * @brief printArr
 * 
 * @param arr  the array to print
 * @param size  the size of the array
 */

void printArr(int *arr, int size)
{
    printf("%d", *arr);
    for (int i = 1; i < size; i++)
    {
        printf(",%d", *(arr + i));
    }
    printf("\n");
}
/**
 * @brief shift_element
 * 
 * @param arr  the array to shift
 * @param i  the index of the element to shift
 */

void shift_element(int* arr, int i)
{
   for(int j=0;j<i;j++)
   {
       *(arr+i-j)=*(arr+i-j-1);
   }
}
/**
 * @brief insertion_sort
 * 
 * @param arr  the array to sort
 * @param len  the length of the array
 */
void insertion_sort(int* arr, int len) {
    int count;
   
    for (int i = 1; i < len; i++) {
        int *key = (arr + i-1);
         count = 0;
        while (*key>=*(arr+i))
        {
            count=count+1;
            key=key-1;
            
            if(key+1==arr)
            {
                break;
            }
        }
        key=key+1;
        int temp=*(arr+i);
        shift_element(key,count);
        *key=temp;      
    }
}
/**
 * @brief main
 * 
 * @return int  0 if success 
 */
int main()
{
    int arr[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        scanf(" %d", (arr + i));
    }
    insertion_sort(arr, SIZE);
    printArr(arr, SIZE);
    return 0;
}
