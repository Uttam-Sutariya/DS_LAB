// write a program to find fatorial of a number (using recursion)

#include <stdio.h>

int fact(int n){
    if(n==0) return 1;
    return n * fact(n-1);
}

void main(){
    int n;
    printf("\nEnter the number : ");
    scanf("%d" , &n);
    printf("%d ! = %d", n, fact(n));
}