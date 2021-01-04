#include <stdio.h>
#include <stdbool.h>

#define SIZE 100

// function declarations
void exit(int code); // explicit declaration of exit()
void menu();
void enqueue();
void dequeue();
void display();
bool isEmpty();
bool isFull();

int queue[SIZE];
static int front = -1;
static int rear = -1;

int main() {
    menu();
    return 0;
}

/*** Function Definitions ***/

// function to insert element
void enqueue() {
    if(isFull()) {
        printf("\nQueue overflow!\n");
        return;
    }

    if(isEmpty())
        front = 0;

    printf("\nEnter data: ");
    scanf("%d", &queue[++rear]);

    printf("\nElement inserted\n");
}

// function to delete element
void dequeue() {
    if(isEmpty()) {
        printf("\nQueue underlow!\n");
        return;
    }

    printf("\nElement %d is removed\n", queue[front++]);
}

// function to display queue
void display() {
    if(isEmpty()) {
        printf("\nQueue underflow!\n");
        return;
    }

    printf("\nQueue: ");
    for(int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    
    printf("\n");
}

bool isEmpty() {
    if(front == -1 || front > rear)
        return 1;
    else
        return 0;
}

bool isFull() {
    if(rear == SIZE-1)
        return 1;
    else
        return 0;
}

void menu() {
    char c;

label:
    printf("\nSelect options: \n");
    printf("\n1 - Enqueue");
    printf("\n2 - Dequeue");
    printf("\n3 - Display");
    printf("\n0 - Exit\n\n");

    c = getchar();

    while(1) {
        switch(c) {
            case '1': enqueue();
                break;

            case '2': dequeue();
                break;

            case '3': display();
                break;

            case '0': exit(0);

            default: printf("\nSelect correct option!\n");
        }
        getchar(); // clear input buffer
        goto label;
    }
}
