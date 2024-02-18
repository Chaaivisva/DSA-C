#include<stdio.h>
#include<stdlib.h>

struct node{
    struct node *lc;
    int data, height;
    struct node *rc;
};

struct node *root;

struct node* newnode(int val){
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = val;
    temp->height = -1;
    temp->rc = '\0';
    temp->lc = '\0';
    return temp;
}

int maximum(int a, int b){
    return a>b?a:b;
}

int height(struct node *root){
    if(root == '\0'){
        return -1;
    }
    else{
        return root->height;
    }
}

struct node* RR(struct node *k2){
    struct node *k1 = k2->lc;
    k2->lc = k1->rc;
    k1->rc = k2;

    k2->height = maximum(height(k2->lc), height(k2->rc))+1;
    k1->height = maximum(height(k1->lc), height(k1->rc))+1;

    return k1;
}

struct node* LL(struct node *k2){
    struct node *k1 = k2->rc;
    k2->rc = k1->lc;
    k1->lc = k2;

    k2->height = maximum(height(k2->lc), height(k2->rc))+1;
    k1->height = maximum(height(k1->lc), height(k1->rc))+1;

    return k1;
}

void RL(struct node *k3){
    k3->rc = RR(k3);
    k3 = LL(k3);
}

void LR(struct node *k3){
    k3->lc = LL(k3);
    k3 = RR(k3);
}

struct node* bsinsert(struct node *root, int val){
    if(root == '\0'){
        root = newnode(val);
    }
    else if(root->data < val){
        root->rc = bsinsert(root->rc, val);
    }
    else if(root->data > val){
        root->lc = bsinsert(root->lc, val);
    }
    return root;
}

void insert(struct node *t, int val){
    if(t == '\0'){
        t = newnode(val);
    }
    else if(t->data > val){
        t = bsinsert(t->lc, val);
        if(height(t->lc) - height(t->rc) == 2){
            if(t->lc->data > val){
                RR(t);
            }
            else{
                LR(t);
            }
        }
    }
    else if(t->data < val){
        t = bsinsert(t->rc, val);
        if(height(t->rc) - height(t->lc)  == 2){
            if(t->rc->data > val){
                LL(t);
            }
            else{
                RL(t);
            }
        }
    }
    t->height = maximum(height(t->lc), height(t->rc))+1;
}

struct node* minvaluenode(struct node *root){
    struct node *curr = root;
    while(curr->lc != '\0'){
        curr = curr->lc;
    }
    return curr;
}


struct node* deletion(struct node *root, int val){
    if(root == '\0'){
        return root;
    }
    else if(root->data > val){
        root->lc = deletion(root->lc, val);
    }
    else if(root->data < val){
        root->rc = deletion(root->rc, val);
    }
    else{
        if(root->lc == '\0'){
            struct node *temp = root->rc;
            free(root);
            return temp;
        }
        else if(root->rc == '\0'){
            struct node *temp = root->lc;
            free(root);
            return temp;
        }
    }
    struct node *temp = minvaluenode(root->rc);

    root->data = temp->data;

    root->rc = deletion(root->rc, temp->data);

}


void inorder(struct node *root){
    if(root != '\0'){
        inorder(root->lc);
        printf("%d", root->data);
        inorder(root->rc);
    }
}

int main(){
    int opt, val;
    while(1){
        printf("1. Insert\n");
        printf("2. inorder\n");
        printf("3. Exit\n");
        printf("Enter Your choice : ");
        scanf("%d", &opt);
        switch(opt){
        case 1:
            printf("Enter your value : ");
            scanf("%d", &val);
            root = bsinsert(root, val);
            break;
        case 2:
            if(root == '\0'){
                printf("Can't Be Null");
            }
            else{
                inorder(root);
            }
            break;
        case 4:
            printf("Enter the value : ");
            scanf("%d", &val);
            root = deletion(root, val);
            break;
        case 3:
            exit(0);
        }
    }
}
