#include <stdio.h>
#include <string.h>
#define N 200

char s[N];
int top = -1;

void push(char x){
    if(top<N)
        s[++top] = x;
}

char pop(){
    if(top>=0)
        return s[top--];
    return '#';
}

char peek(){
    if(top>=0)
        return s[top];
    return '#';
}

int isOperand(char x){
    return (x >= 'a' && x <= 'z') || (x >= 'A' && x <= 'Z');
}

int prec(char ch){
    switch(ch){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;

        default:    
            return -1;
    }
}

void infixToPostFix(char str[]){
    char polish[N];
    int i, k = -1;

    for(int i = 0 ; i<strlen(str) ; i++){
        if(isOperand(str[i])){
            polish[++k] = str[i];
        }
        else if(str[i]=='('){
            push(str[i]);
        }
        else if(str[i]==')'){
            while(top!=-1 && peek()!='('){
                polish[++k] = pop();
            }
            pop();
        }
        else{
            while(top!=-1 && prec(str[i]) <= prec(peek())){
                polish[++k] = pop();
            }
            push(str[i]);
        }
    }

    while(top!=-1){
        polish[++k] = pop();
    }
    polish[++k] = '\0';
    printf("\nInfix : %s\n", str);
    printf("Postfix : %s\n\n", polish);
}   

void main(){
    // char str[] = "a+b+c*d";
    char str[] = "a+b*(c^d-e)^(f+g*h)-i";
    infixToPostFix(str);
}
