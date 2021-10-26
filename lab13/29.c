/*
Read n numbers from user and sort them in ascending order and print sorted array using insertion sort algorithm
*/

#include <stdio.h>

//sort the array using insertion sort algorithm
void insertionSort(int arr[], int n){
    int i, j, value;
    for(i = 1 ; i<n ; i++){
        value = arr[i];
        j = i-1;

        //moving value to its correct position if it's smaller than arr[i]
        while(j>=0 && arr[j]>value){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = value;
    }
}


void main(){
    int n;

    //reading the number of elements of an array
    printf("\nEnter the number of elements of an array : ");
    scanf("%d", &n);

    //initializing array of size entered by user
    int arr[n];

    //reading the array
    printf("\nEnter the elements of an array: \n");
    for(int i = 0 ; i<n ; i++){
        printf("%d element : ", i+1);
        scanf("%d" , &arr[i]);
    }

    printf("\nBefore sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);

    insertionSort(arr, n);

    printf("\n\nAfter sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}