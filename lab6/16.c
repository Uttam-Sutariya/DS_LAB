/*
Write a program to evaluate of prefix expression using stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//stack structure
struct Stack
{
    int top;
    double capacity;
    char* arr;
};

//create stack of given input string size
struct Stack* createStack(double capacity){
    struct Stack* stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (char*)malloc(sizeof(capacity * sizeof(char)));
    return stack;
}

//check if the stack is empty or not
int isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

//peek the top element of the stack
int isEmpty(struct Stack* stack){
    return stack->top < 0;
}

//push the character on the top of the stack
void push(struct Stack* stack, char x){
    if(isFull(stack)){
        printf("\nStack Overflow\n");
        return;
    } 
    else
        stack->arr[++stack->top] = x;
}

//remove & return the top element of the stack
char pop(struct Stack* stack){
    if(isEmpty(stack)){
        printf("\nStack Underflow\n");
    } 
    else
        return stack->arr[stack->top--];
}

int isDigit(char x){
    return x-'0' >= 0 && x-'0' <= 9;
}

//this function evaluate prefix expression
void evaluate_prefix(struct Stack* stack , char str[]){
    for (int i = strlen(str)-1; i >=0 ; i--){
        char t = str[i];
        if(isDigit(t)){
            push(stack, t - '0');
        }
        else{
            int op1 = pop(stack);
            int op2 = pop(stack);
            switch (str[i])
            {
                case '+': push(stack, op1 + op2); break;
                case '-': push(stack, op1 - op2); break;
                case '*': push(stack, op1 * op2); break;
                case '/': push(stack, op1/op2); break;
            }
        }
    }
    printf("Answer = %d\n\n", pop(stack));
}

// driven code
void main(){
    char str[100];
    printf("\n");
    scanf("%s", str);
    struct Stack *stack = createStack(strlen(str));
    evaluate_prefix(stack, str);
}
