#include<stdio.h>
#include<stdlib.h>

int binary_search(int key, int low,int high, int arr[]){
    while(low<=high){
        int mid = (low + (high-low)) / 2;
        if(arr[mid] == key){
           return mid;
        }
        else if(arr[mid] < key){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    int Size;
    printf("Enter the Size of an array : ");
    scanf("%d", &Size);
    int arr[Size];
    printf("Enter the Elements in an Array : \n");
    for(int i=0; i<Size; i++){
        scanf("%d", &arr[i]);
    }
    int key;
    printf("Enter the Key : ");
    scanf("%d", &key);
    int result = binary_search(key, 0,Size-1, arr);

    if(result == -1){
        printf("Not Found");
    }
    else{
        printf("Found at the position %d", (result+1));
    }
}
