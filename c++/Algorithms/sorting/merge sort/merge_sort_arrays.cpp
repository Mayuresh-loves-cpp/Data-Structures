#include <iostream>
#include <stdlib.h>
#include <time.h>

// array class
class arr {
    public:
    int *a;
    long int length;
    arr(long int len) {
        length = len;
        a = new int[len];
    }
};

// function generates array of random numbers
// returns base address of array
int* generateRamdomArray(long int length) {
    int* array = new int(length);
    srand(time(0));
    for(int i = 0; i < length; i++) {
        array[i] = rand()%(1000000+1-(-1000000))+(-1000000);
    }
    return array;
}

// function takes manually numbers from user
int* take_array(long int length) {
    int* array = new int(length);
    for(int i = 0; i < length; i++) {
        std::cout << ": ";
        std::cin >> array[i];
    }
    return array;
}

// function displays array
void display_array(arr* array) {
    std::cout << " [";
    for(int i = 0; i < array -> length; i++) {
        std::cout << array -> a[i];
        if(i < array -> length -1) {
            std::cout << ", ";
        }
    }
    std::cout << "]" << std::endl;
}

void merge(int low, int mid, int high, arr* array, bool resverse) {
    int l = high - low, l1 = mid + 1;
    int *tmp_array = new int(l);
    l = 0;
    if (!resverse) {
        int l1 = mid + 1;
        while(low <= mid && l1 <= high) {
            if (array -> a[low] < array -> a[l1]) {
                tmp_array[l++] = array -> a[low++];
            }
            else {
                tmp_array[l++] = array -> a[l1++];
            }
        }
        for (; low <= mid; low++) {
            tmp_array[l++] = array -> a[low];
        }
        for (; l1 <= high; l1++) {
            tmp_array[l++] = array -> a[l1];
        }
    }
    else {
        int l1 = mid + 1;
        while(low <= mid && l1 <= high) {
            if (array -> a[low] > array -> a[l1]) {
                tmp_array[l++] = array -> a[low++];
            }
            else {
                tmp_array[l++] = array -> a[l1++];
            }
        }
        for (; low <= mid; low++) {
            tmp_array[l++] = array -> a[low];
        }
        for (; l1 <= high; l1++) {
            tmp_array[l++] = array -> a[l1];
        }
    }
    l = high - low;
    for (int i = 0; i <= l; i++) {
        array -> a[i] = tmp_array[i];
    }
}

// merge sort for ascending order
void merge_sort_ascending(int low, int high, arr* array) {
    std::cout << std::endl << "in merge sort ascending";
    int mid;
    if(low < high) {
        std::cout << std::endl << "in if condition"; 
        mid = (low + high) / 2;
        merge_sort_ascending(low, mid, array);
        merge_sort_ascending(mid + 1, high, array);
        merge(low, mid, high, array, false);
    }
}

// merge sort for descending order
void merge_sort_descending(int low, int high, arr* array) {}

void sort_manual() {
    long int length;

    std::cout << std::endl;
    jmp : std::cout << "How many numbers you will enter: ";
    std::cin >> length;
    if(length < 1) {
        std::cout << "length should be non-negative and greater than 0!" << std::endl;
        goto jmp;
    } 
    arr* input_array = new arr(length);
    std::cout << std::endl << "Enter array: -" << std::endl;
    input_array -> a = take_array(length);
    std::cout << std::endl <<"Choose corting type ascending or descending(type a or d): ";
    char c;
    jump : std::cin >> c;
    switch(c) {
        case 'a':
            std::cout << std::endl <<"Sorting array..." << std::endl << std::endl;
            merge_sort_ascending(0, length, input_array);
            break;
        case 'd':
            std::cout << std::endl << "Sorting array..." << std::endl << std::endl;
            merge_sort_descending(0, length, input_array);
            break;
        default:
            std::cout << "plaese enter proper option!" << std::endl;
            goto jump;
    }

    std::cout << "Your sorted array is:";
    display_array(input_array);
    std::cout << std::endl;    
}

void sort_random() {
    long int length = 0;

    std::cout << std::endl;
    jmp : std::cout << "How many random numbers you want to generate: ";
    std::cin >> length;
    if(length < 1) {
        std::cout << "length should be non-negative and greater than 0!" << std::endl;
        goto jmp;
    }   
    arr* input_array = new arr(length);
    
    input_array -> a = generateRamdomArray(length);
    
    std::cout << std::endl << "Numbers that are generated:";
    display_array(input_array);
    std::cout << std::endl;
    
    std::cout << "Choose corting type ascending or descending(type a or d): ";
    char c;
    jump : std::cin >> c;
    switch(c) {
        case 'a':
            std::cout << std::endl <<"Sorting array..." << std::endl << std::endl;
            merge_sort_ascending(0, length, input_array);
            break;
        case 'd':
            std::cout << std::endl << "Sorting array..." << std::endl << std::endl;
            merge_sort_descending(0, length, input_array);
            break;
        default:
            std::cout << "plaese enter proper option!" << std::endl;
            goto jump;
    }

    std::cout << "Your sorted array is:";
    display_array(input_array);
    std::cout << std::endl;
}

// main operation function
void operations() {
    std::cout << std::endl << "Enter: -" << std::endl;
    std::cout << "  1 - if you to generate array of random numbers" << std::endl;
    std::cout << "  2 - if you want to enter numbers manualy" << std::endl;
    std::cout << ": ";
    jump : switch (getchar()) {
        case '1':
            sort_random();
            break;
        case '2':
            sort_manual();
            break;
        default:
            goto jump;
    }
}

// main function
int main() {
    operations();
}