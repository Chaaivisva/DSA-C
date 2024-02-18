#include<stdio.h>
#include<stdlib.h>

struct bsnode{
    struct bsnode *rc;
    int data;
    struct bsnode *lc;
};

struct bsnode *root;

struct bsnode* newnode(int val){
    struct bsnode* temp;
    temp = (struct bsnode *)malloc(sizeof(struct bsnode));
    temp->data = val;
    temp->rc = '\0';
    temp->lc = '\0';
    return temp;
}

struct bsnode* bsinsert(struct bsnode *root, int val){
    if(root == '\0'){
        root =  newnode(val);
    }
    else if(root->data > val){
        root->lc = bsinsert(root->lc, val);
    }
    else if(root->data < val){
        root->rc = bsinsert(root->rc, val);
    }
    return root;
}

struct bsnode* minvalnode(struct bsnode* node){
    struct bsnode *curr = node;
    while(curr->lc != '\0'){
        curr = curr->lc;
    }
    return curr;
}

struct bsnode* maxvalnode(struct bsnode* node){
    struct bsnode *curr = node;
    while(curr->rc != '\0'){
        curr = curr->rc;
    }
    return curr;
}

struct bsnode* deletion(struct bsnode* root, int val){
    if(root == '\0'){
        return root;
    }
    else if(val < root->data){
        root->lc = deletion(root->lc, val);
    }
    else if(val > root->data){
        root->rc = deletion(root->rc, val);
    }
    else{
        if(root->rc == '\0'){
            struct bsnode* temp = root->lc;
            free(root);
            return temp;
        }
        else if(root->lc == '\0'){
            struct bsnode* temp = root->rc;
            free(root);
            return temp;
        }
    struct bsnode *temp = minvalnode(root->rc);

    root->data = temp->data;

    root->rc = deletion(root->rc, temp->data);
    }
    return root;
}

void search(struct bsnode* root, int val){
    if(root != '\0'){
        if(root->data > val){
            search(root->lc, val);
        }
        else if(root->data < val){
            search(root->rc, val);
        }
        else{
            printf("Found");
        }
    }
    else{
        printf("Found");
    }
}

void inorder(struct bsnode *root){
    if(root != '\0'){
        inorder(root->lc);
        printf("%d", root->data);
        inorder(root->rc);
    }
}

void preorder(struct bsnode *root){
    if(root != '\0'){
        printf("%d", root->data);
        preorder(root->lc);
        preorder(root->rc);
    }
}

void postorder(struct bsnode *root){
    if(root != '\0'){
        postorder(root->lc);
        postorder(root->rc);
        printf("%d", root->data);
    }
}

int main(){
    int opt,val;
    struct bsnode *min,*max;

    while(1){
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Inorder");
        printf("\n4.Preorder");
        printf("\n5.Postorder");
        printf("\n6.Minimum value");
        printf("\n7.Maximum value");
        printf("\n8.Search");
        printf("\n9.Exit");
        printf("\nEnter option ");
        scanf("%d",&opt);

        switch (opt)
        {

        case 1:
            printf("\nEnter value ");
            scanf("%d",&val);
            root=bsinsert(root,val);
            break;
        case 2:
            if(root == NULL)
                printf("No values to delete\n");
            else{
                printf("\nEnter value ");
                scanf("%d",&val);
                root = deletion(root,val);
            }
            break;
        case 3:
            if(root == NULL)
                printf("No values to display\n");
            else
                inorder(root);printf("\n");
            break;
        case 4:
            if(root == NULL)
                printf("No values to display\n");
            else
                preorder(root);printf("\n");
            break;
        case 5:
            if(root == NULL)
                printf("No values to display\n");
            else
                postorder(root);printf("\n");
            break;
        case 6:
            if(root == NULL)
                printf("There is no Tree \n");
            else{
                min = minvalnode(root);
                printf("Minimum value %d\n",min->data);
            }
            break;
        case 7:
            if(root == NULL)
                printf("There is no Tree \n");
            else{
                max = maxvalnode(root);
                printf("Maximum value %d\n",max->data);
            }
            break;
        case 8:
            if(root == NULL)
                printf("No values to Search\n");
            else{
                printf("\nEnter value ");
                scanf("%d",&val);
                search(root,val);
            }
            break;
        case 9:
            return 0;
        }
    }


}
