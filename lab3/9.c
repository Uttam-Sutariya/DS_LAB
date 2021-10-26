// Write a c program to swap two numbers using user defined function (call by referance)

#include <stdio.h>

//call by referance
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;   
}

void main(){
    int a, b;
    printf("\nEnter two numbers\n");
    scanf("%d%d" , &a, &b);

    printf("\nBefore swaping\n");
    printf("a = %d\nb = %d", a, b);

    swap(&a,&b);
    
    printf("\nAfter swaping\n");
    printf("a = %d\nb = %d", a, b);
}