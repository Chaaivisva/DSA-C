#include<stdio.h>
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
        swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void quicksort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi-1);
        quicksort(arr, pi+1, high);
    }
}

void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        printf("%d", arr[i]);
    }
}

int main(){
    int n;
    printf("Enter the Size of an Array : ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the Elements in an Array : ");
    for(int i=0; i< n; i++){
        scanf("%d", &arr[i]);
    }

    quicksort(arr, 0, n-1);
    printArray(arr, n);

    return 0;
}