#include "linked_list.h"
#include <iostream>

using namespace std;

void swap(node* a,node* b) {
    node* tmp = new node;
    tmp -> data = a -> data;
    a -> data = b -> data;
    b -> data = tmp -> data;
}

void sort_list_ascending(node* head, unsigned int length) {
    node* tmp = new node;
    for(node* i = head; i -> next != NULL; i =  i -> next) {
        for(node* j = head; j -> index < length - i -> index - 1 ; j = j -> next) {
            if (j -> data > j -> next -> data) {
                swap(j, j -> next);
            }
        }
    }
}

void sort_list_descending(node* head, unsigned int length) {
    cout << "in descending sort!";
    node* tmp = new node;
    for(node* i = head; i -> next != NULL ; i =  i -> next) {
        for(node* j = head; j -> index > length - i -> index - 1; j = j -> next) {
            if (j -> data > j -> next -> data) {
                swap(j, j -> next);
            }
        }
    }
}

void operations() {
    unsigned int length;
    cout << endl << "How many numbers you want to enter: ";
    cin >> length;

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
        // case 'd':
        //     sort_list_descending(head_ptr, length);
        //     break;
        default:
            goto jump;
    }
    
    list.display_list(head_ptr);
}
int main() {
    operations();
    return 0;
}
