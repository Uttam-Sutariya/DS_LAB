/*
Read n numbers from user and sort them in ascending order and print sorted array using merge sort algorithm
*/

#include <stdio.h>

//merge two sorted arrays
void merge(int arr[], int l, int m, int r){
    int n1, n2;
    n1 = m-l+1;
    n2 = r-m;

    //creating two temporary array
    int L[n1], R[n2];

    //copying data to temporary arrays
    for(int i = 0 ; i<n1 ; i++)
        L[i] = arr[l+i];
    for(int i = 0 ; i<n2 ; i++)
        R[i] = arr[m+1+i];

    //merge two temporary array back to main array arr[l...r]
    int i, j, k;
    i = j = 0;
    k = l;
    while(i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    //copy the remaining elements of L[]
    while(i<n1)
        arr[k++] = L[i++];

    //copy the remaining elements of R[]
    while(j<n2)
        arr[k++] = R[j++];
}

void mergerSort(int arr[], int l, int r){
    if(l<r){
        //mid position of array
        int m = l + (r-l)/2;

        //sorting first and second halves recursively
        mergerSort(arr, l, m);
        mergerSort(arr, m+1, r);

        //merging sorted arrays
        merge(arr, l, m, r);
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

    mergerSort(arr, 0, n-1);

    printf("\n\nAfter sorting\n");
    for(int i = 0 ; i<n ; i++)
        printf("%d ", arr[i]);

    printf("\n\n");
}