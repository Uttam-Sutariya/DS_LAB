/*
Read n numbers from user and sort them in ascending order and print sorted array using bubble sort algorithm
*/

#include <stdio.h>

//swap two numbers (call by reference)
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//this function sort an array using bubble sort algorithm
//compare two adjacent elements and swap them if they are in wrong order
void bubbleSort(int arr[], int n){
    for(int i = 0 ; i<n-1 ; i++)
        //last i elements are already in their place
        for(int j = 0 ; j<n-i-1 ; j++)
            if(arr[j]>arr[j+1])
                swap(&arr[j], &arr[j+1]);
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

    bubbleSort(arr, n);

    //printing the array
    printf("\n\nAfter sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}