//Implement a program to create a node of singly linked list. Read the data in node, print the node and release the memory of the node

#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

int main(){
    //creating head node
    struct Node* head = NULL;
    head = (struct Node*)malloc(sizeof(struct Node));       //allocating memory dynamically

    //reading data of node
    int x;
    printf("\nEnter the data to add into the node : ");
    scanf("%d", &x);

    //initializing fields
    head->data = x;
    head->next = NULL;
    
    //printing data
    printf("\nData of the node : %d\n\n", head->data);
    printf("Node:\n");
    printf("%d -> ", head->data);
    printf("NULL\n\n");
    
    //releasing memory of the node
    free(head);
    return 0;
}