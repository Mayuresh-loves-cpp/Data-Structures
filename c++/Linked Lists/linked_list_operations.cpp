/****************************************
 * 
 * linked list,
 * By Mayuresh Shinde
 * 
****************************************/

#include <iostream>
#include <conio.h>

// node class
class node {
    public:
    int data;
    struct node* next;
};

// linked list class, has all the functions
// for all operstions
class linked_list {
    public:
    class node* head = new node;
    class node* head_pointer = new node;
    void make_list1();
    void make_list2();
    void make_list(int length);
    bool isEmpty();
    void display_list();
    void menu();
    void make_list();
    void insert();
    void remove();
    void append();
    void append_beg();
    void append_end();
    linked_list() {
        head_pointer = NULL;
    }
};

// creates list of one node
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

// creates list of n nodes
void linked_list :: make_list(int length) {
    std::cout << "Enter list: -" << std::endl;
    int ip, i = 2;
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
    while(i < length){ 
        head = new node;
        std::cout << ": ";
        std::cin >> ip;
        head -> data = ip;
        head ->next = NULL;
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

// checks list if empty
bool linked_list::isEmpty() {
    if(head_pointer == NULL) {
        return true;
    }
    else{
        return false;
    }
}

// displays list
void linked_list::display_list() {
    std::cout << std::endl << "list: -" << std::endl;
    if(isEmpty()) {
        std::cout << "list is empty!" << std::endl;
        menu();
    }
    class node* display_pointer = new node;
    display_pointer = head_pointer;
    while (display_pointer != NULL){
        std::cout << ": " << display_pointer -> data << std::endl;
        display_pointer = display_pointer -> next;
    }
    menu();
}

// function for making list according to
// given input
void linked_list::make_list() {
    int length;
    std::cout << std::endl << "Enter length of list : ";
    std::cin >> length;
    if(length == 1){
        make_list1();
    }
    else if(length == 2){
        make_list2();
    }
    else{
        make_list(length);
    }
    std::cout << "List created!" << std::endl;
    menu();
}

// function to insert element in the list
void linked_list::insert() {
    int position, value;
    std::cout << std::endl << "please enter position value : ";
    std::cin >> position;
    std::cout << "please enter value : ";
    std::cin >> value;
    class node* traverse_pointer = new node;
    class node* backup_link = new node;
    class node* new_node = new node;
    traverse_pointer = head_pointer;
    for(int i = 1 ; i < position - 1 ; i++){
        traverse_pointer = traverse_pointer -> next;
    }
    backup_link = traverse_pointer -> next;
    traverse_pointer -> next = new_node;
    new_node -> data = value;
    new_node -> next = backup_link;
    std::cout << "list modified!" << std::endl;
    menu();
}

// funtion to remove element in the list
void linked_list::remove() {
    int position;
    std::cout << std::endl << "Enter position of element to delete : ";
    std::cin >> position;
    class node* traverse_pointer = new node;
    class node* previous = new node;
    traverse_pointer = head_pointer;
    if(position == 1){
        head_pointer = head_pointer -> next;
    }
    for(int i = 1 ; i < position - 1 ; i++){
        traverse_pointer = traverse_pointer -> next;
    }
    previous = traverse_pointer -> next;
    traverse_pointer -> next = previous -> next;
    std::cout << "list modified!" << std::endl;
    menu();
}

// function to append element at beginning
void linked_list::append_beg() {
    int value;
    std::cout << std::endl << "Enter value to be added at beginning : ";
    std::cin >> value;
    class node* new_node = new node;
    new_node -> data = value;
    new_node -> next = head_pointer;
    head_pointer = new_node;
    std::cout << "list modified!" << std::endl;
    menu();
}

// function to append element at end
void linked_list::append_end() {
    int value;
    std::cout << std::endl << "Enter value to be added at end : ";
    std::cin >> value;
    class node* traverse_pointer = new node;
    class node* previous = new node;
    traverse_pointer = head_pointer;
    while (traverse_pointer != NULL){
        previous = traverse_pointer;
        traverse_pointer = traverse_pointer -> next;
    }
    class node* new_node = new node;
    new_node -> data = value;
    new_node -> next = NULL;
    previous -> next = new_node;
    std::cout << "list modified!" << std::endl;
    menu();
}

// menu function
void linked_list::menu() {
    std::cout << std::endl << "Select options: - (press key)" << std::endl;
    std::cout << "1 - make linked list" << std::endl;
    std::cout << "2 - show linked list" << std::endl;
    std::cout << "3 - insert element" << std::endl;
    std::cout << "4 - delete element" << std::endl;
    std::cout << "5 - append at beginning" << std::endl;
    std::cout << "6 - append at end" << std::endl;
    std::cout << "0 - exit" << std::endl;
    char select; 
    jump : select = getch();
    while(select == '0' || select == '1' || select == '2' || select == '3' || select == '4' || select == '5' || select == '6' ){
        jmp : switch (select)
        {
        case '1':
            make_list();
            break;

        case '2':
            display_list();
            break;

        case '3':
            insert();
            break;

        case '4':
            remove();
            break;

        case '5':
            append_beg();
            break;

        case '6':
            append_end();
            break;

        case '0':
            exit(0);

        default:
            std::cout << "Please press proper key!" << std::endl;
            break;
        }
        select = getch();
    }
    goto jump;
}

// main funtion
int main() {
    linked_list instance;
    instance.menu();
}