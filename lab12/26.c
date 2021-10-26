/*
Writre a program to implement a linear search
*/

#include <stdio.h>

//this function preforms linear search and return index of an element if present else return -1
int linearSeaarch(int arr[], int n, int x){
    for(int i = 0 ; i<n ; i++)
        if(arr[i]==x)
            return i;
    return -1;
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

    int x, index;
    printf("\nEnter the element to search : ");     //reading the element to be searched 
    scanf("%d", &x);

    index = linearSeaarch(arr, n, x); 

    if(index==-1){
        printf("\nElement is not present in an array\n\n");
        return;
    }
    printf("\n%d is present at index : %d\n\n", x, index);
}