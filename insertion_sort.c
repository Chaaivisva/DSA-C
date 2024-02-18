#include<stdio.h>

void insertion_sort(int arr[], int N){
    int i,j,key;
    for(i=0; i<N; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

void printArray(int arr[], int N){
    for(int i=0; i<N; i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the Size of an Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements in an Array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);
    printArray(arr, n);
}
