/*
Write a program to implement binary search
*/

#include <stdio.h>

//to perfrom binary search array must be sorted !!!
//this function performs binary search and return index of an element if present else return -1
int binarySearch(int arr[], int n, int x){
    int low = 0;
    int high = n-1;

    while(low<=high){
        int mid = low + (high-low) / 2;     //mid point of array
        if(arr[mid]==x)         //if arr[mid]==x the mid is the required index
            return mid;
        else if(arr[mid]>x)     //if arr[mid]>x then right array from mid will be neglected
            high = mid-1;
        else                    //if arr[mid]<x then left array from mid will be neflected
            low = mid+1;
    }   
    return -1;                  //if element not found return -1
}

void main(){
    int n;

    //reading the number of elements of an array
    printf("\nEnter the number of elements of an array : ");
    scanf("%d", &n);

    //initializing array of size entered by user
    int arr[n];

    //reading the array
    printf("\nEnter the elements of an array: \nPlease enter in ascending order\n");
    for(int i = 0 ; i<n ; i++){
        printf("%d element : ", i+1);
        scanf("%d" , &arr[i]);
    }

    int x, index;
    printf("\nEnter the element to search : ");     //reading the element to be searched 
    scanf("%d", &x);

    index = binarySearch(arr, n, x); 

    if(index==-1){
        printf("\nElement is not present in an array\n\n");
        return;
    }
    printf("\n%d is present at index : %d\n\n", x, index);
}