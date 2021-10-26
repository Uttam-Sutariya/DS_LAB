/* Write a menu driven program to implement following operations on doubly linked list
a. Insert a node at the front of the linked list
b. Delete a node from the specified position 
c. Insert a node at the end of the linked list
d. Display all nodes
*/

#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* prev;
    struct Node* next;
};

struct Node* createNode(int x){
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->next = NULL;
    temp->data = x;
    return temp;
}

struct Node* insertFirst(struct Node* head, int x){
    struct Node* toAdd = createNode(x);
    if(head==NULL)
        return toAdd;

    toAdd->next = head;
    head->prev = toAdd;
    return toAdd;
}

struct Node* insertLast(struct Node* head, int x){
    struct Node* toAdd = createNode(x);
    if(head==NULL)
        return toAdd;

    struct Node* temp = head;
    while(temp->next!=NULL)
        temp = temp->next;
    temp->next = toAdd;
    toAdd->prev = temp;
    return head;    
}

struct Node* deleteAtGivenPos(struct Node* head, int pos){
    struct Node* temp = head;
    if(pos==1){
        temp = temp->next;
        free(temp->prev);
        temp->prev = NULL;
        return temp;
    }
    while(pos>2 && temp->next!=NULL){
        temp = temp->next;
        pos--;
    }
    
    // if node is not found at given position
    if(temp->next==NULL){
        printf("\nNode not found at given position\n");
        return head;
    }

    //if the node to be deleted is the last node
    if(temp->next->next==NULL){
        struct Node* toDelete = temp->next;
        temp->next = NULL;
        free(toDelete);
        return head;
    }

    //if the node to be deleted is not first and last node
    struct Node* Nnext = temp->next->next;      //next node of the node to be deleted
    temp->next = Nnext;
    Nnext->prev = temp;
    free(temp->next);
    return head;
}

void display(struct Node* head){
    if(head==NULL){
        printf("\nLinked list empty\n");
        return;
    }
    struct Node* temp = head;
    printf("\nLinked list\n");
    while(temp!=NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void main(){
    struct Node* head = NULL;
    int x;
    do{
        int y, pos;
        printf("\n\nEnter:\n1 to insert first\n2 to insert last\n3 to delete at given position\n4 to display all nodes\n0 to exit\n\n");
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d", &y);
                head = insertFirst(head, y);
                break;

            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d" , &y);
                head = insertLast(head, y);
                break;

            case 3:
                printf("\nEnter the position to delete the node : ");
                scanf("%d", &pos);
                head = deleteAtGivenPos(head, pos);
                break;
            
            case 4:
                display(head);
                break;

            case 0:
                exit(EXIT_FAILURE);

            default:
                printf("\nPlease enter valid number for operation\n");
        }
    }while(x);
}