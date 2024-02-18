#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
int queue[N], front = -1, rear = -1;

void enqueue(int temp){
    if(front == -1 && rear == -1){
        front = 0;
        rear = 0;
        queue[front] = temp;
    }
    else if((rear+1) % N == front){
        printf("Queue is Full");
    }
    else{
        rear = (rear+1) % N;
        queue[rear] = temp;
    }
}

void dequeue(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty");
    }
    else if(front == rear){
        front = -1;
        rear = -1;
    }
    else{
        front = (front+1) % N;
    }
}

void print(){
   int i;
   while(i!=rear){
        printf("%d", queue[i]);
        i = (i + 1) % N;
   }
}

int main(){
    int temp;
    printf("Enter the value : ");
    scanf("%d", &temp);

    enqueue(temp);
    enqueue(temp);
    enqueue(temp);
    enqueue(temp);
    print();

    dequeue();
    print();
    return 0;
}
