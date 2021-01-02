#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

// function declarations
void exit(int code); // explicit declaration of exit()
void menu();
void push();
void pop();
void peek();
void display();
bool isEmpty();
bool isFull();

int stack[SIZE];
static int TOP = -1;

int main() {
    menu();
    return 0;
}

/*** Function Definitions ***/

// function to insert element
void push() {
    if(isFull()) {
        printf("\nStack overflow!\n");
        return;
    }

    printf("\nEnter element: ");
    scanf("%d", &stack[++TOP]);

    printf("\nElement pushed\n");
}

// function to delete element
void pop() {
    if(isEmpty()) {
        printf("\nStack underflow!\n");
        return;
    }

    printf("\nPopped element: %d\n", stack[TOP--]);
}

// function to display top element
void peek() {
    if(isEmpty()) {
        printf("\nStack underflow!\n");
        return;
    }

    printf("\nTop element: %d\n", stack[TOP]);
}

// function to display stack
void display() {
    if(isEmpty()) {
        printf("\nStack underflow!\n");
        return;
    }

    printf("\nStack:\n");
    for(int i = TOP; i >= 0; i--)
        printf("  %d\n", stack[i]);
    
    printf("\n");
}

bool isEmpty() {
    if(TOP == -1)
        return 1;
    else
        return 0;
}

bool isFull() {
    if(TOP == SIZE-1)
        return 1;
    else
        return 0;
}

void menu() {
    char c;

label:
    printf("\nSelect options: \n");
    printf("\n1 - Push");
    printf("\n2 - Pop");
    printf("\n3 - Peek");
    printf("\n4 - Display");
    printf("\n0 - Exit\n\n");

    c = getchar();

    while(1) {
        switch(c) {
            case '1': push();
                break;

            case '2': pop();
                break;

            case '3': peek();
                break;

            case '4': display();
                break;

            case '0': exit(0);

            default: printf("\nSelect correct option!\n");
        }
        getchar(); // clear input buffer
        goto label;
    }
}