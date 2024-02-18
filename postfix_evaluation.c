#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define Max 100

char postfix[Max],stack[Max];
int top = -1;

char pop();
void push(char);
void posToeval();
void print();

int main(){
    printf("Enter the postfix evaluation : ");
    gets(postfix);

    posToeval();
    print();
}

void posToeval(){
    int i,j=0;
    char symbol, next;
    for(int i=0; i < strlen(postfix); i++){
        symbol = postfix[i];
        switch(symbol){
        case '+':{
            int a,b,c;
            a = pop();
            b = pop();
            c = a+b;
            push(c);
            break;
        }
        case '-':{
            int e,f,g;
            f = pop();
            e = pop();
            g = f - e;
            push(g);
            break;
        }
        case '*':{
            int h,i,j;
            h = pop();
            i = pop();
            j = h * i;
            push(j);
            break;
        }
        case '/':{
            int k,l,m;
            l = pop();
            k = pop();
            m = l/k;
            push(m);
            break;
        }
        default:{
            int d;
            d = symbol - '0';
            push(d);
        }
        }
    }
}

void print(){
            printf("%d", stack[top]);
}

void push(char symbol){
    if(top == Max-1){
        printf("Stack is Full");
    }
    else{
        top++;
        stack[top] = symbol;
    }
}

char pop(){
    if(top == -1){
        printf("Stack is Empty");
    }
    else{
        char c;
        c = stack[top];
        top--;
        return c;
    }
}

