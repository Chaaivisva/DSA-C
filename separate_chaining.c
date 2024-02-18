#include<stdio.h>
#include<stdlib.h>
#define Table_size 10

struct node{
    int data;
    struct node *link;
};

struct node *head[Table_size]={'\0'}, *c;

void insert(){
    int i,key;
    printf("Enter the Key : ");
    scanf("%d", &key);

    i = key % Table_size;
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = i;
    newnode->link = '\0';

    if(head[i] == '\0'){
        head[i] = newnode;
    }
    else{
        c = head[i];
        while(c->link != '\0'){
            c = c->link;
        }
        c->link = newnode;
    }
}
void search(){
    if(head[i] == '\0'){
        printf("can't search");
    }
    else{
        for(c=head[i]; c!='\0';c=c->link){
                if(c->data == key){
                    printf("Found");
                    break;
                }
        }
        if(c->link == '\0'){
            printf("Not Found");
        }


}

void display()
{
    int i;
    for(i=0;i<TABLE_SIZE;i++)
          {
           printf("\nentries at index %d\n",i);
               if(head[i] == NULL)
               {
               printf("No Hash Entry");

               }
               else
               {
                for(c=head[i];c!=NULL;c=c->next)
                printf("%d->",c->data);
               }
          }
}
