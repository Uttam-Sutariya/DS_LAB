// Implement simple queue using array that performs following operations : INSERT, DELETE, DISPLAY

#include <stdio.h>
#define N 5

//Queue is represented by q[N] of size N
int q[N];

//initializing front & rear pointer of queue
int f = -1, r = -1;

//queue manipulation functions
void insert(int);
int delete();
void display();

//driven code
void main(){
    insert(10);
    insert(20);
    insert(30);
    delete();
    display();
}

//this function insert an element at the rear(end) of the queue
void insert(int x){

    //check for overflow
    if(r>=N-1){
        printf("\nQueue Overflow\n");
        return;
    }
    r++;
    q[r] = x;
    if(f==-1) f = 0;
}

//this function delete an element from the front of the queue
int delete(){

    //check for underflow
    if(f==-1){
        printf("Queue Underflow");
        return -1;
    }
    int y = q[f];

    if(f==r)    
        f = r = -1;
    else
        f++;

    return y;
}


//this function print queue
void display(){
    for(int i = f ; i<=r ; i++){
        printf("%d ", q[i]);
    }
}