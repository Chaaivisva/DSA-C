#include<stdio.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int i, int N){
    int largest = i;
    int left = 2*i + 1;
    int right = 2*i + 2;

    if(N>left && arr[left]>arr[largest]){
        largest = left;
    }
    if(N>right && arr[right]>arr[largest]){
        largest = right;
    }
    while(largest != i){
        swap(&arr[i], &arr[largest]);

        heapify(arr, N, largest);
    }
}

void heapsort(int arr[], int N){
    for(int i = N-1 / 2; i>=0; i--){
        heapify(arr, N, i);
    }

    for(int i=N-1; i>=0; i--){
        swap(&arr[0], &arr[i]);

        heapify(arr, i, 0);
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
    printf("Enter the elements in an Array : ");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    heapsort(arr, n);
    printArray(arr, n);
}
