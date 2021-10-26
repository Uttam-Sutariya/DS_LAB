// write a program to find fatorial of a number (using loop)

#include <stdio.h>

void main(){
    int n;
    int fact = 1;
    printf("\nEnter the number : ");
    scanf("%d" , &n);
    int i = n;
    while(i>0){
        fact = fact * i;
        i--;
    }
    printf("%d ! = %d", n, fact);
}