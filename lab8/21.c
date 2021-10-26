/*
Write a program to implement stack using linked list
*/

#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

//this indicate empty stack
struct Node* head = NULL;

//push element into the stack
void push(int x){
    //creating new node
    struct Node* toAdd = (struct Node*)malloc(sizeof(struct Node));
    toAdd->data = x;

    //make the new pointing to the head node
    toAdd->next = head;

    //make the new node as the head node
    head = toAdd;
}

//delete and return the top element from the stack
void pop(){
    
    //head==null indecates empty stack
    if(head == NULL){
        printf("\nStack is empty\n");
        return;
    }

    //toPop is the node to be deleted
    struct Node* toPop = head;

    //moving head ahead
    head = head->next;

    printf("\n%d is poped out from the stack\n", toPop->data);    
    free(toPop);
}

//to print content of stack
void display(){
    if(head==NULL){
        printf("\n-----Stack is empty-----\n");
        return;
    }
    struct Node* temp = head;

    printf("\n\nStack content\n");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

//Driven code
void main(){
    int x;
    do{
        int y;
        printf("\n\nEnter:\n1 to push\n2 to pop\n3 to display\n0 to exit\n");
        scanf("%d", &x);

        switch(x){
            case 1:
                printf("\nEnter the value to push : ");
                scanf("%d", &y);
                push(y);
                break;

            case 2:
                pop();
                break;
            
            case 3:
                display();
                break;

            case 0:
                exit(EXIT_FAILURE);

            default:
                printf("\nPlease enter valid number for operation\n");

        }
    }while(x);
}