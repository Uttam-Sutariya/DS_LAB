/*
Read n numbers from user and sort them in ascending order and print sorted array using selection sort algorithm
*/

#include <stdio.h>

//swap two numbers (call by reference)
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//sort the array using selection sort
//find the minimum element from the unsorted array and swap it with its appropriate index element
void selectionSort(int arr[], int n){
    int min_index;

    for(int i = 0 ; i<n-1 ; i++){
        //finding the minimum element in unsorted array
        min_index = i;
        for(int j = i+1 ; j<n ; j++)
            if(arr[j]<arr[min_index])
                min_index = j;

        //swap the minimum element with its appropriate index
        swap(&arr[i], &arr[min_index]);
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

    selectionSort(arr, n);

    //printing the array
    printf("\n\nAfter sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);
    printf("\n\n");
}