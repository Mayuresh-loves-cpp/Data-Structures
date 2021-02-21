// including necessary headers
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

// array class
class arr {
    public:
    int *a;
    long int length;
    arr(long int len) {
        length = len;
        int* a = new int[len];
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

// function displays array
void display_array(arr* array) {
    cout << " [";
    for(int i = 0; i < array -> length; i++) {
        cout << array -> a[i];
        if(i < array -> length -1) {
            cout << ", ";
        }
    }
    cout << "]" << endl;
}

// selection sort for ascending order
void selection_sort_ascending(arr* array) {
    int min, tmp;
    for(int i = 0; i < array -> length - 1; i++) {
        min = i;
        for(int j = i + 1; j < array -> length; j++) {
            if(array -> a[j] < array -> a[min]) {
                min = j;
            }
        }
        tmp = array -> a[min];
        array -> a[min] = array -> a[i];
        array -> a[i] = tmp;
    }
}

// selection sort for ascending order
void selection_sort_descending(arr* array) {
    int min, tmp;
    for(int i = 0; i < array -> length - 1; i++) {
        min = i;
        for(int j = i + 1; j < array -> length; j++) {
            if(array -> a[j] > array -> a[min]) {
                min = j;
            }
        }
        tmp = array -> a[min];
        array -> a[min] = array -> a[i];
        array -> a[i] = tmp;
    }
}

// workflow function for random numbers sort
void sort_random() {
    long int length = 0;

    cout << endl;
    jmp : cout << "How many random numbers you want to generate: ";
    cin >> length;
    if(length < 1) {
        cout << "length should be non-negative and greater than 0!" << endl;
        goto jmp;
    }   
    arr* input_array = new arr(length);
    
    input_array -> a = generateRamdomArray(length);
    
    cout << endl << "Numbers that are generated:";
    display_array(input_array);
    cout << endl;
    
    cout << "Choose corting type ascending or descending(type a or d): ";
    char c;
    jump : cin >> c;
    switch(c) {
        case 'a':
            cout << endl <<"Sorting array..." << endl << endl;
            selection_sort_ascending(input_array);
            break;
        case 'd':
            cout << endl << "Sorting array..." << endl << endl;
            selection_sort_descending(input_array);
            break;
        default:
            cout << "plaese enter proper option!" << endl;
            goto jump;
    }

    cout << "Your sorted array is:";
    display_array(input_array);
    cout << endl;
}

// function takes manually numbers from user
int* take_array(long int length) {
    int* array = new int(length);
    for(int i = 0; i < length; i++) {
        cout << ": ";
        cin >> array[i];
    }
    return array;
}

// workflow function for manually inputed number sort
void sort_manual() {
    long int length;

    cout << endl;
    jmp : cout << "How many numbers you will enter: ";
    cin >> length;
    if(length < 1) {
        cout << "length should be non-negative and greater than 0!" << endl;
        goto jmp;
    } 
    arr* input_array = new arr(length);
    cout << endl << "Enter array: -" << endl;
    input_array -> a = take_array(length);
    cout << endl <<"Choose corting type ascending or descending(type a or d): ";
    char c;
    jump : cin >> c;
    switch(c) {
        case 'a':
            cout << endl <<"Sorting array..." << endl << endl;
            selection_sort_ascending(input_array);
            break;
        case 'd':
            cout << endl << "Sorting array..." << endl << endl;
            selection_sort_descending(input_array);
            break;
        default:
            cout << "plaese enter proper option!" << endl;
            goto jump;
    }

    cout << "Your sorted array is:";
    display_array(input_array);
    cout << endl;
}

// main operation function
void operations() {
    cout << endl << "Enter: -" << endl;
    cout << "  1 - if you to generate array of random numbers" << endl;
    cout << "  2 - if you want to enter numbers manualy" << endl;
    cout << ": ";
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