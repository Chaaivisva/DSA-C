#include<stdio.h>
#include<stdlib.h>
int n=0;
struct node{
    int data;
    struct node *link;
};

struct node *head, *temp, *curr;

void insert_front(){
    if(head == '\0'){
        head = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        head->data = value;
        head->link = '\0';
        n++;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        temp->data = value;
        temp->link =head;
        head = temp;
        n++;
    }
}

void insert_back(){
    if(head == '\0'){
        head = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        head->data = value;
        head->link = '\0';
        n++;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        temp->data = value;
        temp->link = '\0';
        curr = head;
        while(curr->link != '\0'){
            curr = curr->link;
        }
        curr->link = temp;
        n++;
    }
}

void delete_front(){
    if(head == '\0'){
        printf("Can't delete.");
    }
    else{
        head = head->link;
        n--;
    }
}

void delete_back(){
    if(head == '\0'){
        printf("Can't delete.");
    }
    else{
        curr = head;
        while(curr->link->link != '\0'){
            curr = curr->link;
        }
        curr->link = '\0';
        n--;
    }
}

void insert_pos(int pos){
    if(head == '\0'){
        head = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        head->data = value;
        head->link = '\0';
        n++;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        temp->data = value;
        temp->link = '\0';
        curr = head;
        for(int i=0; i < pos-1; i++){
            curr = curr->link;
        }
        temp->link = curr->link;
        curr->link = temp;
        n++;
    }
}

void delete_pos(int pos){
    if(head == '\0'){
        printf("Not correct.");
    }
    else{
        curr = head;
        for(int i=0; i < pos-1; i++){
            curr = curr->link;
        }
        curr->link = curr->link->link;
        n--;
    }
}

void insert_inorder(){
    if(head == '\0'){
        head = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        head->data = value;
        head->link = '\0';
        n++;
    }
    else{
        temp = (struct node *)malloc(sizeof(struct node));
        int value;
        printf("Enter the data : ");
        scanf("%d", &value);
        temp->data = value;
        temp->link ='\0';
        curr =head;
        while(curr->link->data >= value){
            curr = curr->link;
        }
        temp->link = curr->link;
        curr->link = temp;
    }
}

void print(){
    curr = head;
    while(curr->link != '\0'){
        printf("%d", curr->data);
        curr = curr->link;
    }
    if(curr->link == '\0'){
        printf("%d", curr->data);
    }
}

int main(){
    insert_front();
    insert_back();
    insert_front();
    print();
    insert_inorder();
    print();
    delete_front();
    print();
    delete_back();
    print();
    return 0;

}
