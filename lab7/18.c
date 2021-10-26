// Implement circular queue using array that performs following operations : INSERT, DELETE, DISPLAY

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
    insert(40);
    insert(50);
    delete();
    delete();
    insert(60);
    insert(70);
    display();
}

//this function insert an element at the rear(end) of the queue
void insert(int x){
    
    // reset rear pointer
    if(r==N-1)    
        r=0;
    else
        r++;
    
    // check overflow
    if(f==r){   
        printf("\nQueue Overflow\n");
        return;
    }

    // insert element
    q[r] = x;   

    // is front pointer properly set
    if(f==-1)   
        f=0;
}

//this function delete an element from the front of the queue
int delete(){
    
    //check for underflow
    if(f==-1){       
        printf("\nQueue Underflow\n");
        return -1;
    }
    int y = q[f];
    q[f] = -1;
    if(f==r){
        f = r = -1;
        return y;
    }

    //reset front pointer
    if(f==N-1)        
        f = 0;
    else 
        f++;
    return y;
}

//this function print queue
void display(){
    if(f<=r){
        for(int i = f ; i<=r ; i++){
            printf("%d ", q[i]);
        }
    } else {
        for(int i = f ; i<N ; i++)
            printf("%d ", q[i]);
        for(int i = 0 ; i<=r ; i++)
            printf("%d ", q[i]);
    }
}