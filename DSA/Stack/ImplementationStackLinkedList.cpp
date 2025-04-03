#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;
    
    node(int val) {
        data = val;
        next = nullptr;
    }
};

class Stack {
public:
    int top;
    int capacity;
    int* stack;

    Stack(int size) {
        capacity = size;
        stack = new int[capacity];
        top = -1;
    }

    void insert(int val) {
        if (top == capacity - 1) {
            cout << "Stack Overflow!" << endl;
            return;
        }
        stack[++top] = val;
    }

    void display() {
       
        if (top == -1) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <=top; i++) {
            cout << stack[i] << " ";
        }
        cout << endl;
    }

};

node* insertLL(node* head, int data) {
    node* temp = new node(data);
    if (head == nullptr) {
        return temp;
    }
    temp->next = head;
    return temp;
}

void PushFromLinkedList(node* head, Stack& stack) {
    node* current = head;
    if (current == nullptr) {
        cout << "No Linked List Available!" << endl;
        return;
    }
    
    while (current != nullptr) {
        stack.insert(current->data);
        current = current->next;
    }
}

int main() {
    node* head = nullptr;
    
    head = insertLL(head, 5);
    head = insertLL(head, 6);
    head = insertLL(head, 4);

    Stack s1(5);
    
    PushFromLinkedList(head, s1);
    
    s1.display();
    
    return 0;
}
