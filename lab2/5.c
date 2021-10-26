// Read n numbers in array and print it using pointers

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

    //printing
    printf("\nPrinting using pointers\n");
    for(int i = 0 ; i<n ; i++){
        printf("%d ", *(arr+i));
    }
}