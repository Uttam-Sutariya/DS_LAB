// Read n numbers in array then read two different numbers, replace 1st number with 2nd number in array then print its index and final array

#include <stdio.h>

void main(){
    int n;
    printf("\nEnter the number of array elements : ");
    scanf("%d", &n);
    int arr[n];

    //reading array
    printf("\nReading the array\n");
    for(int i = 0 ; i<n ; i++){
        printf("Enter %d element : ", i+1);
        scanf("%d" , &arr[i]);
    }

    int a,b,temp = 0;
    printf("\nEnter two numbers\n");
    scanf("%d%d", &a, &b);
    int i = 0;
    //searching for element
    for( ; i<n ; i++){
        if(arr[i]==a){
            temp = 1;
            arr[i] = b;
            break;
        }
    }
    if(temp)
        printf("\nIndex = %d\n", i);
    else
        printf("\nElement not found!!!\n");

    printf("\nFinal array\n");
    for(int j = 0 ; j<n ; j++)
        printf("%d ", arr[j]);
}