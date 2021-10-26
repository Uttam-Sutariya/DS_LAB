/*
Read n numbers from user and sort them in ascending order and print sorted array using quick sort algorithm
*/

#include <stdio.h>

//this function swap two elements
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

//this function return the correct position of pivot element
int partition(int arr[], int l, int r){
    //take last element as pivot element
    int pivot = arr[r];

    //i is the previous index of the lowest index
    int i = l-1;

    //swap ith element with jth if arr[j] < pivot
    for(int j = l ; j<r ; j++){
        if(arr[j]<pivot){
            i++;
            swap(arr, i, j);
        }
    }

    //swap i+1 element with r th position as element at position i is the last smallest element than pivot
    swap(arr, i+1, r);
    return i+1;
}

void quickSort(int arr[], int l, int r){
    if(l<r){
        
        //making partiotion around pivot element
        int pi = partition(arr, l ,r);
        quickSort(arr, l, pi-1);
        quickSort(arr, pi+1, r);
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

    quickSort(arr, 0, n-1);

    printf("\n\nAfter sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}