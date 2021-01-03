#pragma once

#include <iostream>

class node {
    public:
    int data;
    unsigned int index;
    struct node* next;
};

// linked list class, has all the functions
// for all operations
class linked_list {
    public:
    class node* head = new node;
    class node* head_pointer = new node;
    void make_list(unsigned int length);
    bool isEmpty();
    void make_list1();
    void make_list2();
    int display_list(node* head);
    node* get_head_pointer();
    linked_list() {
        head_pointer = nullptr;
    }
};



void linked_list :: make_list(unsigned int length) {
    int ip, i = 2;
    unsigned int counter = 0;
    std::cout << "Enter list: -" << std::endl;
    
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
    if(isEmpty()) {
        std::cout << "list is empty!" << std::endl;
        return -1;
    }
    std::cout << std::endl << "your sorted list is: [";
    class node* display_pointer = new node;
    display_pointer = head;
    while(display_pointer != NULL) {
        std::cout << display_pointer -> data;
        if(display_pointer -> next != NULL) {
            std::cout << ", "; 
        }
        else {
            std::cout << "]" << std::endl;
        }
        display_pointer = display_pointer -> next;
    }
    std::cout << std::endl;
    return 0;
}

bool linked_list::isEmpty() {
    if(head_pointer == NULL) {
        return true;
    }
    else{
        return false;
    }
}
// creates list of one nodes
void linked_list :: make_list1() {
    int ip;
    std::cout << ": ";
    std::cin >> ip;
    head -> data = ip;
    head -> next = NULL;
    head_pointer = head;
}

// creates list of two nodes
void linked_list :: make_list2() {
    int ip;
    std::cout << ": ";
    std::cin >> ip;
    head -> data = ip;
    head -> next = NULL;
    head_pointer = head;
    class node* second = new node;
    std::cout << ": ";
    std::cin >> ip;
    second -> data = ip;
    second -> next = NULL;
    head -> next = second;
}
