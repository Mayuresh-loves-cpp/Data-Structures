#include <iostream>
using namespace std;
 
class data_array {
    public:
    int length, *arr;
    data_array(int len) {
        arr = new int(length);
        length = len;
    }
};
 
data_array take_array(int length) {
    cout << endl << "Enter number: -" << endl;
    data_array input(length);
    for(int i = 0; i < length; i++) {
        cout << ": ";
        cin >> input.arr[i];
    }
    return input;
}

data_array sort_array_ascending(data_array array) {
    int temp;
    for (int i = 0; i < array.length - 1; i++){
        for (int j = 0; j < array.length - 1 - i; j++){
            if (array.arr[j] > array.arr[j + 1]){
                temp = array.arr[j];
                array.arr[j] = array.arr[j + 1];
                array.arr[j + 1] = temp;
            }
        }
    }
    return array;
}

data_array sort_array_descending(data_array array) {
    int temp;
    for (int i = 0; i < array.length - 1; i++){
        for (int j = 0; j < array.length - 1 - i; j++){
            if (array.arr[j] < array.arr[j + 1]){
                temp = array.arr[j];
                array.arr[j] = array.arr[j + 1];
                array.arr[j + 1] = temp;
            }
        }
    }
    return array;
}

void display_array(data_array array) {
    cout << endl << "your sorted array is: [";
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
    cout << endl << "How many numbers you want to enter: ";
    cin >> length;

    data_array input_array(length);

    input_array = take_array(length);

    char type;
    jump : cout << endl << "choose sorting type ascending or descending (type a or d): ";
    cin >> type;
    switch (type) {
        case 'a':
            input_array = sort_array_ascending(input_array);
            break;
        case 'd':
            input_array = sort_array_descending(input_array);
            break;
        default:
            goto jump;
    }

    
    display_array(input_array);
}
 
int main() {
    operations();
    return 0;
}