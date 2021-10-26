/*
Write a program to implement queue using linked list
*/

#include<stdio.h>
#include<stdlib.h>

//Node structure
struct Node{
    int data;
    struct Node *next;
};

//initializing front and rear pointer of the queue
struct Node *front = NULL, *rear = NULL;


//this function add element at the rear(last) position of the queue
void enqueue(int x){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    //if it is the first Node
    if(front == NULL && rear == NULL)
        //make both front and rear points to the new Node
        front = rear = newNode;
    else
    {
        //add newNode in rear->next
        rear->next = newNode;

        //make the new Node as the rear Node
        rear = newNode;
    }
}

//this function delete element from the front(first) position of the queue
void dequeue()
{
    //used to free the first Node after dequeue
    struct Node *temp;

    if(front == NULL)
         printf("\nQueue is Empty. Unable to perform dequeue\n");
    else
    {
        //take backup
        temp = front;

        //make the front Node points to the next Node
        //logically removing the front element
        front = front->next;

        //if front == NULL, set rear = NULL
        if(front == NULL)
            rear = NULL;

        printf("\n%d is dequeued\n", temp->data);
       //free the first Node
       free(temp);
    }

}

//to print the content of the queue
void display(){

    if(front==NULL){
        printf("\nQueue is empty\n");
        return;
    }

    struct Node *temp = front;
    printf("\nQueue\n");
    while(temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main()
{
    int x;
    do{
        int y;
        printf("\n\nEnter:\n1 to enqueue\n2 to dequeue\n3 to display\n0 to exit\n");
        scanf("%d", &x);

        switch(x){
            case 1:
                printf("\nEnter the value to enqueue : ");
                scanf("%d", &y);
                enqueue(y);
                break;

            case 2:
                dequeue();
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

