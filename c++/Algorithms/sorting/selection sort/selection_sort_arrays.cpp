#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class data_array {
    public:
    int length, *arr;
    data_array(int len) {
        length = len;
        arr = new int(length);
    }
};

data_array generateRamdomArray(int length) {
    data_array array(length);
    srand(time(0));
    for(int i = 0; i < length; i++) {
        array.arr[i] = rand()%(10000+1-(-10000))+(-10000);
    }
    return array;
}

data_array take_array(int length) {
    cout << endl << "Enter number: -" << endl;
    data_array input(length);
    for(int i = 0; i < length; i++) {
        cout << ": ";
        cin >> input.arr[i];
    }
    return input;
}

int getMinElementPosition(data_array array, int first) {
    int min = array.arr[first], minPos = -1;
    for(int i = first; i < array.length; i++) {
        if(min > array.arr[i]) {
            minPos = i;
        }
    }
    return minPos;
}

int getMaxElementPosition(data_array array, int first) {
    int min = array.arr[first], minPos = -1;
    for(int i = first; i < array.length; i++) {
        if(min < array.arr[i]) {
            minPos = i;
        }
    }
    return minPos;
}

data_array sort_array_ascending(data_array given_array) {
    int tmp, pos;
    for(int i = 0; i < given_array.length; i++) { 
        pos = getMinElementPosition(given_array, i);
        if(pos >= 0 && pos < given_array.length) {
            tmp = given_array.arr[i];
            given_array.arr[i] = given_array.arr[pos];
            given_array.arr[pos] = tmp;
        }
    }
    return given_array;
}

data_array sort_array_descending(data_array given_array) {
    int tmp, pos;
    for(int i = 0; i < given_array.length; i++) { 
        pos = getMaxElementPosition(given_array, i);
        if(pos >= 0 && pos < given_array.length) {
            tmp = given_array.arr[i];
            given_array.arr[i] = given_array.arr[pos];
            given_array.arr[pos] = tmp;
        }
    }
    return given_array;
}

void display_array(data_array array) {
    cout << "[";
    for(int i = 0; i < array.length; i++) {
        cout << array.arr[i];
        if(i < array.length - 1) {
            cout << ", ";
        }
    }
    cout << "]" << endl << endl;
}

void operations() {
    int length;
    
    cout << endl << "Do you want to: -" << endl <<
    endl << "1 - generate array of random numbers" << 
    endl << "2 - or manualy enter numbers" << endl << ": ";
    char c = getchar();
    cout << endl << "Enter size of array: ";
    cin >> length;
    data_array input_array(length);
    jump_1 : switch(c) {
        case '1':
            input_array = generateRamdomArray(length);
            cout << endl << "generated array is: ";
            display_array(input_array);
            break;
        case '2':
            input_array = take_array(length);
            break;
        default:
            cin >> c;
            goto jump_1;
    }
    jump : cout << endl << "choose sorting type ascending or descending (type a or d): ";
    cin >> c;
    switch (c) {
        case 'a':
            input_array = sort_array_ascending(input_array);
            break;
        case 'd':
            input_array = sort_array_descending(input_array);
            break;
        default:
            goto jump;
    }
    cout << endl << "Your sorted array is: ";
    display_array(input_array);
}

int main() {
    operations();
}