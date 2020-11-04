#include <iostream>
#include <conio.h>

class node{
    public:
    int value;
    class node* next;
};

class stack{
    public:
    bool isFull();
    bool isEmpty();
    void push(int data);
    int pop();
    int getTop();
    //void stackInit();
    int maximumCapacity;
    int top;
    class node* head = new node;
    class node* currentNode = new node;

    stack(){
        maximumCapacity = 10;
        top = -1;
    }
};

/*void stack::stackInit(){
    
}*/

bool stack::isFull(){
    if (top == maximumCapacity){
        return true;
    }
    else{
        return false;
    }
}

bool stack::isEmpty(){
    if (top == -1){
        return true;
    }
    else{
        return false;
    }
}

void stack::push(int data){
    class node* newNode = new node;
    newNode -> value = data;
    if(isEmpty()){
        newNode -> next = NULL;
        currentNode = newNode;
    }
    else{
        newNode -> next = currentNode;
        currentNode = newNode;
    }
    
    top++;
}

int stack::pop(){
    int data = getTop();
    currentNode = currentNode -> next;
    top--;
    return data;
}

int stack::getTop(){
    return currentNode -> value;
}

class stackOperations : stack{
    public:
    int usevalue, insertValue, length;
    void menu();
    void createStack();
    void displayStack();
};

void stackOperations::menu(){
    std::cout << std::endl << "press: -" << std::endl << "1 to create list" << std::endl << "2 to pop element"  << std::endl << "3 to push element"  << std::endl << "4 to display stack"  << std::endl << "0 to exit" << std::endl;
    char ip = getch();
    switch (ip){
        case '1':
            createStack();
            break;
        
        case '2':
            usevalue = pop();
            break;

        case '3':
            std::cout << std::endl << "Enter value to be added : ";
            std::cin >> insertValue;
            push(insertValue);
            break;

        case '4':
            displayStack();
            break;

        case '0':
            exit(0);
            break;

        default:
            std::cout << "something unexpected happened!\n";
            break;
    }
    menu();
}

void stackOperations::createStack(){
    std::cout << "Enter length of stack : ";
    std::cin >> length;
    maximumCapacity = length;
    for(int i = 1 ; i <= length ; i++){
        std::cout << ": ";
        std::cin >> insertValue;
        push(insertValue);
    }
    std::cout << "stack created!" << std::endl;
}

void stackOperations::displayStack(){
    class node* traversePointer = new node;
    if (isEmpty()){
        std::cout << std::endl << "stack is empty!" << std::endl;
    }
    else{
        traversePointer = currentNode;
        std::cout << ": " << traversePointer -> value << std::endl;
        do{
            traversePointer = traversePointer -> next;
            std::cout << ": " << traversePointer -> value << std::endl;
        }while (traversePointer -> next != NULL);
    }
}

int main(){
    stackOperations operation;
    operation.menu();
}
