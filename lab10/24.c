/* Write a menu driven program to implement following operations on the circular linked list
a. Insert a node at the font of the linked list
b. Delete a node from the specified position
c. Insert a node at the end to the linked list
d. Display all nodes
*/

#include <stdio.h>
#include <stdlib.h>

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

struct Node* insertFirst(struct Node* tail, int x){
    struct Node* toAdd = createNode(x);
    if(tail == NULL){
        toAdd->next = toAdd;
        return toAdd;
    }
    toAdd->next = tail->next;
    tail->next = toAdd;
    return tail;
}

struct Node* insertLast(struct Node* tail, int x){
    struct Node* toAdd = createNode(x);
    if(tail == NULL){
        toAdd->next = toAdd;
        return toAdd;
    }
    toAdd->next = tail->next;
    tail->next = toAdd;
    return toAdd;
}

struct Node* deleteAtGivenPos(struct Node* tail, int pos){
    struct Node* temp = tail->next;
    if(pos==1){
        tail->next = temp->next;
        free(temp);
        return tail;
    }
    while(pos>2 && temp!=tail){
        temp = temp->next;
        pos--;
    }
    if(temp==tail){
        printf("\nNode not fount at given position\n");
        return tail;
    }
    temp->next = temp->next->next;
    return tail;
}

void display(struct Node* tail){
    if(tail==NULL){
        printf("\n-----Linked list is empty-----\n");
        return;
    }
    struct Node* temp = tail->next;
    printf("\nLinked List\n");
    do{
        printf("%d -> ", temp->data);
        temp = temp->next;
    }while(temp != tail->next);
    printf("first node\n");
}

void main(){
    struct Node* tail = NULL;
    int x;
    do{
        printf("\n\nEnter:\n1 to insert at first\n2 to insert at last\n3 to delete at given position\n4 to display linked list\n0 to exit\n\n");
        int y, pos;
        scanf("%d", &x);
        switch(x){
            case 1:
                printf("\nEnter the value to be inserted : ");
                scanf("%d", &y);
                tail = insertFirst(tail, y);
                break;

            case 2:
                printf("\nEnter the value to be inserted : ");
                scanf("%d", &y);
                tail = insertLast(tail, y);
                break;

            case 3:
                printf("Enter the position to delete a node : ");
                scanf("%d", &pos);
                tail = deleteAtGivenPos(tail, pos);
                break;

            case 4:
                display(tail);
                break;

            case 0:
                exit(EXIT_FAILURE); 
            
            default:
                printf("\nPlease enter valid number for operation\n"); 
        }
    }while(x);
}