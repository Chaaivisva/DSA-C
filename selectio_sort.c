#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int N){
    int i,j, min_index;
    for(i=0; i<N; i++){
        min_index = i;
        for(j=i+1; j<N-1; j++){
            if(arr[j]<arr[min_index]){
                min_index = j;
            }
        }
        if(min_index != i){
            swap(&arr[i], &arr[min_index]);
        }
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
    printf("Enter the Elements in An Array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    selection_sort(arr, n);
    printArray(arr, n);
}
