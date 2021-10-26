// Write a c program to swap two numbers using user defined function (call by value)

#include <stdio.h>

//call by value
void swap(int a, int b){
    printf("\nBefore swaping\n");
    printf("a = %d\nb = %d", a, b);
    int temp = a;
    a = b;
    b = temp;
    printf("\nAfter swaping\n");
    printf("a = %d\nb = %d", a, b);
}

void main(){
    int a, b;
    printf("\nEnter two numbers\n");
    scanf("%d%d" , &a, &b);
    swap(a,b);
}