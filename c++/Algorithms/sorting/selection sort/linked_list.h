#pragma once

#include <iostream>

class node {
    public:
    int data;
    // unsigned int index;
    struct node* next;
};

// linked list class, has all the functions
// for all operations
class linked_list {
    public:
    class node* head = new node;
    class node* head_pointer = new node;
    bool isEmpty();
    void make_list(unsigned int length);
    void make_list(unsigned int length, int* arr);
    int display_list(node* head);
    node* get_head_pointer();
    linked_list() {
        head_pointer = nullptr;
    }
};

// all linked_list class' funtion definations
// this functions creates linked list by taking input from user
void linked_list :: make_list(unsigned int length) {
    int ip, i = 0;
    std::cout << "Enter list: -" << std::endl;
    
    std::cout << ": ";
    std::cin >> ip;
    head -> data = ip;
    head -> next = NULL;
    head_pointer = head;
    i++;

    if(i == length) {
        return;
    }
    
    class node* second = new node;
    std::cout << ": ";
    std::cin >> ip;
    second -> data = ip;
    second -> next = NULL;
    head -> next = second;
    i++;

    if(i == length) {
        return;
    }

    while(i < length){ 
        head = new node;
        std::cout << ": ";
        std::cin >> ip;
        head -> data = ip;
        head -> next = NULL;
        second -> next = head;
        i = i + 1;

        if(i == length) {
            break;
        }

        second = new node;
        std::cout << ": ";
        std::cin >> ip;
        second -> data = ip;
        second -> next = NULL;
        head -> next = second;
        i = i + 1;
    }
}

// this function creates list using elements given in array
void linked_list :: make_list(unsigned int length, int* arr) {
    int i = 0;
    unsigned int counter = 0;
    
    head -> data = arr[counter];
    head -> next = NULL;
    head_pointer = head;
    counter++;
    i++;

    if(i == length) {
        return;
    }
    
    class node* second = new node;
    second -> data = arr[counter];
    second -> next = NULL;
    head -> next = second;
    counter++;
    i++;

    if(i == length) {
        return;
    }

    while(i < length) { 
        head = new node;
        head -> data = arr[counter];
        head ->next = NULL;
        second -> next = head;
        counter++;
        i = i + 1;

        if(i == length) {
            break;
        }

        second = new node;
        second -> data = arr[counter];
        second -> next = NULL;
        head -> next = second;
        i = i + 1;
        counter++;
    }
}

// this funxtion returns head pointer of the list
node* linked_list::get_head_pointer() {
    return head_pointer;
}

// function for displying list by providing it head pointer
int linked_list::display_list(node* head) {
    if(isEmpty()) {
        std::cout << "list is empty!" << std::endl;
        return -1;
    }
    std::cout << "[";
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

// function to check if list is empty
bool linked_list::isEmpty() {
    if(head_pointer == NULL) {
        return true;
    }
    else{
        return false;
    }
}