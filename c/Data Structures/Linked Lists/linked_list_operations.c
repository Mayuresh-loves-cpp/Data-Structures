#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// linked list blueprint
struct list {
    int data;
    struct list* next;
};

static struct list* head;
static int length;

bool is_list_empty() {
    if(head == NULL)
        return 1;
    else
        return 0;
}

// function to create linked list
void create_list() {
    int num;
    struct list *node, *pre;

    printf("\nEnter no. of nodes to create: ");
    scanf("%d", &num);
    length = num;

    if(num == 0) {
        printf("\nNo nodes created!\n");
        return;
    }

    for(int i = 1; i <= num; i++) {
        node = (struct list*)malloc(sizeof(struct list));

        if(node == NULL) {
            printf("\nOut of memory!\n");
            exit(1);
        }

        printf("Enter data of %d node: ", i);
        scanf("%d", &node->data);

        if(is_list_empty()) {
            node->next = NULL;
            head = node;
            pre = node;
        }
        else {
            node->next = NULL;
            pre->next = node;
            pre = node;
        }
    }

    printf("\nLinked list successfully created\n");
}

// function to display list
void display() {
    struct list* traverse;

    if(is_list_empty()) {
        printf("\nList doesn't exist!");
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

// creates new node in existing list
void add_node() {
    int pos;
    struct list *node, *link;

    if(is_list_empty()) {
        printf("\nList doesn't exist!");
        return;
    }

    printf("\nEnter no. of position: ");
    scanf("%d", &pos);

    if(pos > 0 && pos <= length+1) {
        node = (struct list*)malloc(sizeof(struct list));

        if(node == NULL) {
            printf("\nOut of memory!\n");
            exit(1);
        }

        printf("Enter data of new node: ");
        scanf("%d", &node->data);

        if(pos == 1) {
            node->next = head;
            head = node;
        }
        else {
            link = head;

            for(int i = 3; i <= pos; i++)
                link = link->next;
            
            node->next = link->next;
            link->next = node;
        }

        length++;
        printf("\nNew node added\n");
    }
    else
        printf("\nIncorrect position!\n");
}

// deletes node of existing list
void delete_node() {
    int pos;
    struct list *pre_link, *temp;

    if(is_list_empty()) {
        printf("\nList doesn't exist!");
        return;
    }

    printf("\nEnter no. of position: ");
    scanf("%d", &pos);

    if(pos > 0 && pos <= length) {
        if(pos == 1) {
            temp = head;
            head = head->next;
            free(temp);
        }
        else {
            pre_link = head;

            for(int i = 3; i <= pos; i++)
                pre_link = pre_link->next;
            
            temp = pre_link->next;
            pre_link->next = temp->next;
            free(temp);
        }

        length--;
        printf("\nNode deleted\n");
    }
    else
        printf("\nIncorrect position!\n");
}

// menu-driven code
void menu() {
    char c;

    printf("\nSelect options: \n");
    printf("\n1 - Create list");
    printf("\n2 - Display list");
    printf("\n3 - Add new node");
    printf("\n4 - Delete existing node");
    printf("\n0 - Exit\n\n");

    input: c = getchar();

    while(1) {
        switch(c) {
            case '1': create_list();
                break;

            case '2': display();
                break;

            case '3': add_node();
                break;

            case '4': delete_node();
                break;

            case '0': exit(0);

            default: printf("\nSelect correct option!\n");
        }
        getchar(); // clear input buffer
        goto input;
    }
}

int main() {
    menu();
    return 0;
}