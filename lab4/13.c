//Write a program to determine if an input character string is of the form a^ib^i, where i>=1, i.e. Number of 'a' and 'b' are same

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 500

char s[N];      //stack S
int top = -1;   //top of stack

//stack manipulation function
void push(char);
char pop();

//identify the input string if it's valid or not
void recognize(char str[]){
    int countB = 0;
    for(int i = 0 ; i<strlen(str) ; i++){
        if(str[i]=='b') countB++;
        else if(str[i]=='a') push(str[i]);
    }
    while(countB){
        pop();
        countB--;
    }
    if(countB!=0 || top!=-1){
        printf("\nInvalid String\n\n");
    } else {
        printf("\nValid String\n\n");
    }
}

void main(){
    char str[100];
    printf("Enter the string : \n");
    fgets(str, 100, stdin);
    recognize(str);
}

void push(char x){
    //check for overflow
    if(top>=N){
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    s[top] = x;
}

char pop(){
    //check for underflow
    if(top<0){
       printf("\nStack Underflow\n");
        return 'u';
    }
    top--;
    return s[top+1];
}