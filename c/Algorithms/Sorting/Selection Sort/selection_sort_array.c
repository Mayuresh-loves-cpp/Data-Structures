#include <stdio.h>
#include <stdlib.h>

// function to print array
void print(int* arr, int size) {
    for(int i = 0; i < size; i++)
        printf("%d ",  arr[i]);

    printf("\n");
}

// function for swapping two numbers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// selection sort
void sort(int* arr, int size) {
    int min;

    for(int i = 0; i < size-1; i++) {
        min = i; // stores index number;

        for(int j = i+1; j < size; j++) {
            if(arr[j] < arr[min])
                min = j;
        }

        swap(arr+i, arr+min);
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