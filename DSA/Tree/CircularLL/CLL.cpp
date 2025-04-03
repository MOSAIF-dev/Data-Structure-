#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insert(int x) {
        Node* newNode = new Node(x);
        if (isEmpty()) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void remove(int x) {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        Node* prev = nullptr;

        if (head->data == x) {
            if (head->next == head) {
                delete head;
                head = nullptr;
            } else {
                prev = head;
                while (temp->next != head) {
                    temp = temp->next;
                }
                head = head->next;
                temp->next = head;
                delete prev;
            }
        } else {
            while (temp->next != head && temp->data != x) {
                prev = temp;
                temp = temp->next;
            }
            if (temp->data == x) {
                prev->next = temp->next;
                delete temp;
            } else {
                cout << "Element " << x << " not found!" << endl;
            }
        }
    }

    Node* search(int x) {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return nullptr;
        }
        Node* temp = head;
        do {
            if (temp->data == x) {
                return temp;
            }
            temp = temp->next;
        } while (temp != head);
        return nullptr;
    }

    void display() {
        if (isEmpty()) {
            cout << "List is empty!" << endl;
            return;
        }
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

int main() {
    CircularLinkedList list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);
    list.insert(50);

    cout << "Circular Linked List: ";
    list.display();

    int searchVal = 30;
    Node* foundNode = list.search(searchVal);
    if (foundNode) {
        cout << "Element " << searchVal << " found at address: " << foundNode << endl;
    } else {
        cout << "Element " << searchVal << " not found!" << endl;
    }

    int removeVal = 40;
    cout << "Removing element " << removeVal << " from the list." << endl;
    list.remove(removeVal);
    list.display();

    return 0;
}
