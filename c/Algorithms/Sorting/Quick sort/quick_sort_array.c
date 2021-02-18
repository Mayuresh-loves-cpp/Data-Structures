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

// function to partition array
int partition(int* arr, int l, int r) {
    int pivot = l;

    while(l < r) {
        while(arr[l] <= arr[pivot])
            l++;
        
        while(arr[r] > arr[pivot])
            r--;
        
        if(l < r)
            swap(arr+l, arr+r);
    }

    swap(arr+r, arr+pivot);

    return r;
}

// quick sort
void sort(int* arr, int l, int r) {
    if(l < r) {
        int j = partition(arr, l, r);
        sort(arr, 0, j-1);
        sort(arr, j+1, r);
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
    sort(arr, 0, size-1);

    printf("\nSorted array: ");
    print(arr, size);

    free(arr);

    return 0;
}