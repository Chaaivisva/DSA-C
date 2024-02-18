#include<stdio.h>
#define Max 10
int arr[Max], n=0;


void insert_front(int temp){
    if(n == Max-1){
        printf("Array is Full");
    }
    else{
        for(int i=n-1 ; i>=0; i--){
            arr[i+1] = arr[i];
        }
        arr[0] = temp;
        n++;
    }
}

void insert_back(int temp){
    if(n == Max-1){
        printf("Array is Full");
    }
    else{
        arr[n] = temp;
        n++;
    }
}

void delete_front(){
    if(n == -1){
        printf("Array is Empty.");
    }
    else{
        n--;
        for(int i=0; i<n;i++){
            arr[i] = arr[i+1];
        }
    }
}

void delete_back(){
    if(n == -1){
        printf("Array is Empty.");
    }
    else{
        arr[n] = 0;
        n--;
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int temp;
    printf("Enter the Value : ");
    scanf("%d", &temp);

    insert_front(temp);
    insert_back(temp);

    printArray(arr, n);

    delete_front();
    printArray(arr, n);
    delete_back();

    return 0;
}
