#include "linked_list.h"
#include <iostream>

using namespace std;

void swap(node* head,unsigned int pos1) {
    node* traverse_pointer = new node;
    traverse_pointer = head;
    node *tmp1, *tmp2;
    traverse_pointer = head;
    while(traverse_pointer -> next -> index == pos1) {
        traverse_pointer = traverse_pointer -> next;
    }
    tmp1 = traverse_pointer -> next;
    tmp2 = traverse_pointer -> next -> next -> next;
    traverse_pointer -> next = traverse_pointer -> next -> next;
    traverse_pointer -> next -> next = tmp1;
    traverse_pointer -> next -> next -> next = tmp2;
}

node* sort(node* head, int length) {
    node* tmp = new node;
    for(node* i = head; i -> next != NULL ; i -> next) {
        for(node* j = head; j -> index < i -> index - 1 ; j -> next) {
            if (j -> data > j -> next -> data) {
                swap(head, j -> index);
            }
        }
    }
}

void operations() {
    int length;
    cout << endl << "How many numbers you want to enter: ";
    cin >> length;

    linked_list list;
    list.make_list(length);
    node* head_ptr = new node;
    head_ptr = list.get_head_pointer();
    sort(head_ptr, length);
    list.display_list(head_ptr);
}
int main() {
    operations();
    return 0;
}
