#include<stdio.h>

void bubblesort(int arr[], int n){
    int i,j;
    for(i=0; i < n - 1; i++){
        for(j=0; j < n - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void printArray(int arr[], int n){
    for(int i=0; i < n; i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the Size of an Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements in an Array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    bubblesort(arr, n);
    printArray(arr, n);
}
