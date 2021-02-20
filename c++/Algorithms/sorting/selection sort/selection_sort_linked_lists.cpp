#include "linked_list.h"
#include <iostream>

using namespace std;

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

void operations() {
    unsigned int length;
    cout << endl << "How many numbers you want to enter: ";
    cin >> length;
    cout << endl;

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
        cout << endl << "Please provide proper length!";
    }
    
    node* head_ptr = new node;
    head_ptr = list.get_head_pointer();

    char type;
    jump : cout << endl << "choose sorting type ascending or descending (type a or d): ";
    cin >> type;
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
    
    list.display_list(head_ptr);
}

int main() {
    operations();
}