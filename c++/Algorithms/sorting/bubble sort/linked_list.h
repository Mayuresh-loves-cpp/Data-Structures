#pragma once

#include <iostream>

class node {
    public:
    int data;
    unsigned int index;
    struct node* next;
};

// linked list class, has all the functions
// for all operstions
class linked_list {
    public:
    class node* head = new node;
    class node* head_pointer = new node;
    void make_list(int length);
    bool isEmpty();
    int display_list(node* head);
    node* get_head_pointer();
    linked_list() {
        head_pointer = nullptr;
    }
};
