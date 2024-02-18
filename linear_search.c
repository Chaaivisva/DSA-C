#include<stdio.h>
#include<stdlib.h>

int linear_search(int key, int arr[], int Size){
    for(int i=0; i<Size; i++){
            if(arr[i] == key){
                return i;
                break;
            }
    }
    return -1;
}

int main(){
    int Size;
    printf("Enter the Size of an Array : ");
    scanf("%d", &Size);
    int arr[Size];
    printf("Enter the Elements in an Array : \n");
    for(int i=0; i<Size; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the key : ");
    scanf("%d", &key);
    int res = linear_search(key, arr, Size);
    if(res == -1){
        printf("NOT FOUND");
    }
    else{
        printf("Found at the position %d", (res+1));
    }
}
