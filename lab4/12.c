//Implement a program for stack that perform following operations using array : PUSH, POP, PEEP, CHANGE & DISPLAY

#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define N 5     //capacity of stack

int s[N];       //stack S
int top = -1;   //top of stack

//stack manipulation operations
void push(int);
int pop();
int peep(int);
void change(int, int);
void display();

void main(){
    int e;
    do{
        printf("\n\n");
        printf("Enter :\n0 for exit\n1 for push\n2 for pop\n3 for peep\n4 for change\n5 for display\n");
        scanf("%d", &e);
        int x, i;
        switch(e){
            // case 0:
            //     exit(EXIT_FAILURE);
            case 1:
                printf("\nEnter the number to push : ");
                scanf("%d", &x);
                push(x);
                break;
            
            case 2:
                printf("\n%d popped out of the stack\n", pop());
                break;

            case 3:
                printf("\nEnter the value of i : ");
                scanf("%d", &i);
                printf("\n%d is at the position %d from the top of the stack\n", peep(i), i);
                break;

            case 4:
                printf("\nEnter the value of i and x : ");
                scanf("%d%d", &i, &x);
                change(i, x);
                printf("Content of the stack after change\n");
                display();
                break;

            case 5:
                display();
                break;
        }
    }while(e!=0);
    
}

//push the value on the top of thestack
void push(int x){
    //check for overflow
    if(top>=N){
        printf("\nStack Overflow\n");
        return;
    }
    top++;
    s[top] = x;
}

//remove & return element from the top of the stack
int pop(){
    //check for underflow
    if(top<0){
       printf("\nStack Underflow\n");
        return INT_MIN;
    }
    top--;
    return s[top+1];
}

//return ith element from the top of the stack
int peep(int i){
    //check for underflow
    if(top-i+1<0){
        printf("\nStack underflow\n");
        return INT_MIN;
    }
    return s[top-i+1];
}

//change ith element from the top of the stack
void change(int i, int x){
    //check for underflow
    if(top-i+1<0){
        printf("\nStack underflow\n");
    }
    s[top-i+1] = x;
}

//print the stack
void display(){
    printf("\nBottom to top\n");
    for(int i = 0 ; i<=top ; i++)
        printf("%d ", s[i]);
    printf("\nTop to bottom\n");
    for(int i = top ; i>=0 ; i--)
        printf("%d ", s[i]);
}