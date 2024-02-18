#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define N 5
int queue[N],front = -1,rear = -1;

void enqueue(int temp){
    if(front == -1 && rear == -1){
        front++;
        rear++;
        queue[rear] = temp;
    }
    else if(rear == N-1){
        printf("Queue is Full");
    }
    else{
        rear++;
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
        front++;
    }
}

void print(){
    if(front == -1 && rear == -1){
        printf("Queue is Empty");
    }
    else{
        for(int i=0; i<N; i++){
            printf("%d", queue[i]);
        }
    }
}

int main(){
    int temp;
    printf("Enter the value : ");
    scanf("%d", &temp);

    enqueue(temp);
    enqueue(temp);
    print();
    dequeue();
    print();
}
