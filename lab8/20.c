/*Write a menu driven program to implement following operations on singly linked list
a. Insert node at the front of the linked list
b. Display all nodes
c. Deletre first node of the linked list
d. Insert a node at the end of the linked list
e. Delete last node of the linked list
f. Delete a node from the specified position
*/

#include <stdio.h>
#include <stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node* next;
};

//To create node and allocate memory
struct Node* createNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = x;
    temp->next = NULL;
    return temp;
}

//Insert at the first position
struct Node* insertFirst(struct Node* head, int x){
    struct Node* toAdd = createNode(x);
    if(head==NULL)
        return toAdd;
    
    toAdd->next = head;
    return toAdd;
}

//Insert at the last position
struct Node* insertLast(struct Node* head, int x){
    struct Node* toAdd = createNode(x);
    if(head==NULL)
        return toAdd;
    
    struct Node* temp = head;

    //finding the last node
    while(temp->next!=NULL)     
        temp = temp->next;
    temp->next = toAdd;
    
    return head;
}

//Delete first node
struct Node* deleteFirst(struct Node* head){
    if(head==NULL)
        return NULL;
    struct Node* toDelete = head;
    head = head->next;
    free(toDelete);
    return head;
}

//Delete last node
struct Node* deleteLast(struct Node* head){
    struct Node* temp = head;
    
    //finding 2nd last node
    while(temp->next->next != NULL)    
        temp = temp->next;

    struct Node* toDelete = temp;
    temp->next = NULL;
    free(toDelete);
    return head;
}

//Delete at given position
struct Node* deleteAtGivenPos(struct Node* head, int pos){
    struct Node* temp = head;
    if(pos==1)
        return deleteFirst(head);
    while(pos>2 && temp->next!=NULL){
        temp = temp->next;
        pos--;
    }
    if(temp->next==NULL){
        printf("\nNode not found at given position\n");
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = temp->next->next;
    free(toDelete);
    printf("\nNode at %d position is deleted\n", pos);
    return head;
}

//Display all nodes
void display(struct Node* head){
    if(head==NULL){
        printf("\n----Linked List is empty----\n");
        return;
    }
    printf("\nLinked list\n");
    struct Node* temp = head;
    while(temp!=NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

//Driven code
void main(){
    struct Node* head = NULL;
    int x;
    do{
        printf("\n\nEnter:\n1 to insert first\n2 to insert last\n3 to delete first\n4 to delete last\n5 to delete at given position\n6 to display all nodes\n0 to exit\n\n");
        int x, pos;
        scanf("%d" , &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d", &x);
                head = insertFirst(head, x);
                break;
            
            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d", &x);
                head = insertLast(head, x);
                break;

            case 3:
                head = deleteFirst(head);
                printf("\nFirst node deleted\n");
                break;

            case 4:
                head = deleteLast(head);
                printf("\nLast node deleted\n");
                break;
            case 5:
                printf("\nEnter the position to delete the node : ");
                scanf("%d" , &pos);
                head = deleteAtGivenPos(head, pos);
                break;
            case 6:
                display(head);    
                break;

            case 0:
                exit(EXIT_FAILURE);

            default:
                printf("\nPlease enter valid number for operation\n");  
        }

    }while(x);
}