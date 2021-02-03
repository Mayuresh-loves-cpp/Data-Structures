#include <stdio.h>
#include <stdlib.h>

// function to print array
void print(int* arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ",  arr[i]);

    printf("\n");
}

// insertion sort
void sort(int* arr, int size) {
    int key, j;

    for(int i = 1; i < size; i++) {
        key = arr[i];
        j = i-1;

        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main() {
    int size, *arr;

    printf("\nEnter no. of elements to create: ");
    scanf("%d", &size);

    // allocate memory
    arr = (int*)malloc(size * sizeof(int));

    printf("\nEnter data: ");
    for(int i = 0; i < size; i++)
        scanf("%d", arr+i);

    // sort given array
    sort(arr, size);

    printf("\nSorted array: ");
    print(arr, size);

    free(arr);

    return 0;
}