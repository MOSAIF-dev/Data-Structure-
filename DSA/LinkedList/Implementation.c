#include<stdio.h>
#include<stdlib.h>

void createNode();
void InsertAtFirstPosition();
void InsertAtPosition();
void printList();
void clearInputBuffer();

struct node {
    int data;
    struct node *next;
};
typedef struct node* node;

node head = NULL;

void createNode() {
    node temp = (node)malloc(sizeof(struct node));
    if (temp == NULL) {
        printf("Memory full\n");
        exit(1);
    }

    printf("Enter the data of node: ");
    while (scanf("%d", &temp->data) != 1) {
        printf("Invalid input. Please enter an integer value: ");
        clearInputBuffer();
    }
    temp->next = NULL;

    if (head == NULL) {
        head = temp;
    } else {
        node p = head;
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = temp;
    }
}

void InsertAtFirstPosition() {
    node temp1 = (node)malloc(sizeof(struct node));
    if (temp1 == NULL) {
        printf("Memory Allocation failed\n");
        exit(1);
    }

    printf("Enter your new node's data: ");
    while (scanf("%d", &temp1->data) != 1) {
        printf("Invalid input. Please enter an integer value: ");
        clearInputBuffer();
    }

    temp1->next = head;
    head = temp1;
}

void InsertAtPosition() {
    int pos;
    printf("Enter the position where you want to insert a node: ");
    while (scanf("%d", &pos) != 1 || pos <= 0) {
        printf("Invalid position. Please enter a positive integer: ");
        clearInputBuffer();
    }

    node temp2 = (node)malloc(sizeof(struct node));
    if (temp2 == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }

    printf("Enter the data for the node to be inserted at position %d: ", pos);
    while (scanf("%d", &temp2->data) != 1) {
        printf("Invalid input. Please enter an integer value: ");
        clearInputBuffer();
    }

    if (pos == 1) {
        temp2->next = head;
        head = temp2;
        return;
    }

    node p = head;
    int k = 1;
    while (k < pos - 1 && p != NULL) {
        p = p->next;
        k++;
    }

    if (p == NULL) {
        printf("Position out of range.\n");
        free(temp2);
        return;
    }

    temp2->next = p->next;
    p->next = temp2;
}

void printList() {
    if (head == NULL) {
        printf("The list is empty.\n");
        return;
    }

    node p = head;
    printf("The linked list is: ");
    while (p != NULL) {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void clearInputBuffer() {
    while (getchar() != '\n'); // Clear the input buffer
}

int main() {
    int n;

    printf("Enter total number of nodes: ");
    while (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input. Please enter a positive integer: ");
        clearInputBuffer();
    }

    for (int i = 0; i < n; i++) {
        createNode();
    }

    InsertAtFirstPosition();
    InsertAtPosition();
    printList();

    return 0;
}
