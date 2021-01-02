#include "linked_list.h"

void linked_list :: make_list(int length) {
    unsigned int counter = 0;
    std::cout << "Enter list: -" << std::endl;
    int ip, i = 2;
    std::cout << ": ";
    std::cin >> ip;
    head -> data = ip;
    head -> index = counter;
    head -> next = NULL;
    head_pointer = head;
    counter++;
    
    class node* second = new node;
    std::cout << ": ";
    std::cin >> ip;
    second -> data = ip;
    second -> index = counter;
    second -> next = NULL;
    head -> next = second;
    counter++;
    while(i < length){ 
        head = new node;
        std::cout << ": ";
        std::cin >> ip;
        head -> data = ip;
        head -> index = counter;
        head ->next = NULL;
        second -> next = head;
        counter++;
        
        i = i + 1;
        if(i == length) {
            break;
        }

        second = new node;
        std::cout << ": ";
        std::cin >> ip;
        second -> data = ip;
        second -> index = counter;
        second -> next = NULL;
        head -> next = second;
        i = i + 1;
        counter++;
    }
}

node* linked_list::get_head_pointer() {
    return head_pointer;
}

int linked_list::display_list(node* head) {
    std::cout << std::endl << "list: -" << std::endl;
    if(isEmpty()) {
        std::cout << "list is empty!" << std::endl;
        return -1;
    }
    class node* display_pointer = new node;
    display_pointer = head;
    while (display_pointer != NULL){
        std::cout << ": " << display_pointer -> data << std::endl;
        display_pointer = display_pointer -> next;
    }
    return 0;
}
