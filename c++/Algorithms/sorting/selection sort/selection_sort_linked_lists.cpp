#include "linked_list.h"

// using namespace std;

int* generateRamdomArray(long int length) {
    // std::cout << "size: " <<sizeof(length);
    int* array = new int[length];
    srand(time(0));
    for(int i = 0; i < length; i++) {
        array[i] = rand()%(1000000+1-(-1000000))+(-1000000);
    }
    return array;
}


void sort_list_ascending(node* head_ptr,unsigned int length) {
    linked_list display;
    node* min = new node;
    node* i = new node;
    node* j = new node;
    int tmp;
    for(i = head_ptr; i != NULL; i = i -> next) {
        min = i;
        for(j = i -> next; j != NULL; j = j -> next) {
            if(j -> data < min -> data) {
                min = j;
            }
        }
        tmp = i -> data;
        i -> data = min -> data;
        min -> data = tmp;
    }
}

void sort_list_descending(node* head_ptr,unsigned int length) {
    linked_list display;
    node* max = new node;
    node* i = new node;
    node* j = new node;
    int tmp;
    for(i = head_ptr; i != NULL; i = i -> next) {
        max = i;
        for(j = i -> next; j != NULL; j = j -> next) {
            if(j -> data > max -> data) {
                max = j;
            }
        }
        tmp = i -> data;
        i -> data = max -> data;
        max -> data = tmp;
    }
}

void sort_manual() {
    unsigned int length;
    std::cout << std::endl << "How many numbers you want to enter: ";
    std::cin >> length;
    std::cout << std::endl;

    linked_list list;
    if(length == 1) {
        list.make_list1();
    }
    else if(length == 2) {
        list.make_list2();
    }
    else if(length > 2) {
        list.make_list(length);
    }
    else {
        std::cout << std::endl << "Please provide proper length!";
    }
    
    node* head_ptr = new node;
    head_ptr = list.get_head_pointer();

    char type;
    jump : std::cout << std::endl << "choose sorting type ascending or descending (type a or d): ";
    std::cin >> type;
    switch (type) {
        case 'a':
            sort_list_ascending(head_ptr, length);
            break;
        case 'd':
            sort_list_descending(head_ptr, length);
            break;
        default:
            goto jump;
    }
    std::cout << std::endl << "Your sorted numbers are: ";
    list.display_list(head_ptr);
}

void sort_random() {
    long int length;
    linked_list list;
    std::cout << std::endl << "How many numbers you want to generate: ";
    std::cin >> length;

    if(length >= 1) {
        std::cout << std::endl << "Generating list...";
        int* numbers;
        numbers = generateRamdomArray(length);
        list.make_list(length, numbers);
    }
    else {
        std::cout << std::endl << "Please provide proper length!";
        
    }
    
    node* head_ptr = new node;
    head_ptr = list.get_head_pointer();
    std::cout << std::endl << "Generated List: ";
    list.display_list(head_ptr);

    std::cout << "choose sorting type ascending or descending (type a or d): ";
    jump : switch (getchar()) {
        case 'a':
            std::cout << std::endl << "Sorting List...";
            sort_list_ascending(head_ptr, length);
            break;
        case 'd':
            std::cout << std::endl << "Sorting List...";
            sort_list_descending(head_ptr, length);
            break;
        default:
            goto jump;
    }
    std::cout << std::endl << "Your sorted numbers are: ";
    list.display_list(head_ptr);
}

void operations() {
    char pass;
    std::cout << std::endl << "Enter: -" << std::endl;
    std::cout << " 1 - if you to generate array of random numbers" << std::endl;
    std::cout << " 2 - if you want to enter numbers manualy" << std::endl;
    jump : std::cout << " : ";
    std::cin >> pass;
    switch (pass) {
        case '1':
            sort_random();
            break;
        case '2':
            sort_manual();
            break;
        default:
            std::cout << "Please select a proper option!" << std::endl;
            goto jump;
    }
}

int main() {
    operations();
}