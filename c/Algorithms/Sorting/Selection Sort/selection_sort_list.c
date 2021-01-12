#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// linked list blueprint
struct list {
    int data;
    struct list* next;
};

static struct list* head;

// function declarations
bool is_list_empty();
void create_node();
void display();
void sort();
void swap();

// main function
int main() {
    int n;
    printf("\nEnter no. of nodes to create: ");
    scanf("%d", &n);

    while(n--)
        create_node();
    
    // sort linked list
    sort();

    display();

    return 0;
}

/*** Function Definitions ***/

bool is_list_empty() {
    if(head == NULL)
        return 1;
    else
        return 0;
}

// function for node creation
void create_node() {
    struct list* node;
    static struct list* pre_node; // for assigning address of current node

    node = (struct list*)malloc(sizeof(struct list));

    // underflow check
    if(node == NULL) {
        printf("\nOut of memory!\n");
        exit(1);
    }

    printf("Enter data: ");
    scanf("%d", &node->data);

    if(is_list_empty()) {
        node->next = NULL;
        head = node;
        pre_node = node;
    }
    else {
        node->next = NULL;
        pre_node->next = node;
        pre_node = node;
    }
}

// selection sort
void sort() {
    struct list *link1, *link2, *min;

    if(is_list_empty()) {
        printf("\nLinked list doesn't exist!\n");
        return;
    }

    link1 = head;

    while(link1->next != NULL) {
        min = link1; // stores address
        link2 = link1->next;

        while(link2 != NULL) {
            if(link2->data < min->data)
                min = link2;
            
            link2 = link2->next;
        }

        swap(link1, min);
        link1 = link1->next;
    }
}

// function for swapping data
void swap(struct list* p1, struct list* p2) {
    int temp = p1->data;
    p1->data = p2->data;
    p2->data = temp;
}

// function to display list
void display() {
    struct list* traverse;

    if(is_list_empty()) {
        printf("\nLinked list doesn't exist!\n");
        return;
    }

    traverse = head;
    printf("\nList: ");

    while(traverse != NULL) {
        printf("%d ", traverse->data);
        traverse = traverse->next;
    }

    printf("\n");
}
