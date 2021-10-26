// write a programn to check wheather a number is prime or not

#include <stdio.h>
#include <math.h>

void main(){
    int n, isPrime = 1;
    printf("Enter the number : ");
    scanf("%d" , &n);
    if(n==1 || n==2){
        printf("Is a prime number");
    } else {
        for(int i = 2 ; i<=sqrt(n) ; i++){
            if(n%i==0){
                isPrime = 0;
                printf("Not a prime number!\n");
                break;
            }
        }
        if(isPrime)
            printf("Is a prime number");
    }
}