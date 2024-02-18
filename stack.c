#include<stdio.h>
#define Max 10
int stack[Max], top = -1;

void push(int temp){
    if(top == Max-1){
        printf("Stack is Full");
    }
    else{
    top++;
    stack[top] = temp;
    }
}

void pop(){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        top--;
    }
}

void peek(){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        printf("%d", &stack[top]);
    }
}

int isEmpty(){
    return (top==-1);
}
int  isFull(){
    return (top==Max-1);
}

void printArray(int stack[]){
    if(top==-1){
        printf("Stack is Empty");
    }
    else{
        for(int i=0; i<top; i++){
            printf("%d", &stack[i]);
        }
    }
}

int main(){
    int temp;

    printf("Enter the value : ");
    scanf("%d", &temp);

    push(temp);
    printArray(stack);
    printf(isFull());
    printf(isEmpty());
    pop();
    printArray(stack);
}
