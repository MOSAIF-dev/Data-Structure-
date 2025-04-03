#include<iostream>
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

class LinkedList {
private:
    Node* head;
    
public:
    LinkedList() {
        head = nullptr;
    }
    
    void createNode() {
        int value;
        cout << "Enter the data of node: ";
        cin >> value;
        
        Node* temp = new Node(value);
        
        if (head == nullptr) {
            head = temp;
        } else {
            Node* p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = temp;
        }
    }
    
    void InsertAtFirstPosition() {
        int value;
        cout << "Enter your new node's data: ";
        cin >> value;
        
        Node* temp = new Node(value);
        temp->next = head;
        head = temp;
    }
    
    void InsertAtPosition(int pos) {
        int value;
        cout << "Enter the data of the node to insert: ";
        cin >> value;
        
        Node* temp = new Node(value);
        Node* p = head;
        
        if (pos == 1) {
            temp->next = head;
            head = temp;
            return;
        }
        
        int k = 1;
        while (p != nullptr && k < pos - 1) {
            p = p->next;
            k++;
        }
        
        if (p == nullptr) {
            cout << "Position out of range.\n";
            return;
        }
        
        temp->next = p->next;
        p->next = temp;
    }
    
    void DeleteAtBeginning() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }
    
    void DeleteAtPosition(int pos) {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        
        Node* temp = head;
        Node* prev = nullptr;
        
        if (pos == 1) {
            head = head->next;
            delete temp;
            return;
        }
        
        int k = 1;
        while (temp != nullptr && k < pos) {
            prev = temp;
            temp = temp->next;
            k++;
        }
        
        if (temp == nullptr) {
            cout << "Position out of range.\n";
            return;
        }
        
        prev->next = temp->next;
        delete temp;
    }
    
    void SearchElement(int key) {
        Node* p = head;
        while (p != nullptr) {
            if (p->data == key) {
                cout << "Element " << key << " found in the list.\n";
                return;
            }
            p = p->next;
        }
        cout << "Element " << key << " not found in the list.\n";
    }
    
    void printList() {
        if (head == nullptr) {
            cout << "The list is empty.\n";
            return;
        }
        Node* p = head;
        cout << "The linked list is: ";
        while (p != nullptr) {
            cout << p->data << " -> ";
            p = p->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    int n, num, pos, key;
    
    cout << "Enter total number of nodes: ";
    cin >> n;
    
    for (int i = 0; i < n; i++) {
        list.createNode();
    }
    
    list.InsertAtFirstPosition();
    
    cout << "Enter position to be inserted at: ";
    cin >> num;
    list.InsertAtPosition(num);
    
    cout << "Enter position to delete: ";
    cin >> pos;
    list.DeleteAtPosition(pos);
    
    cout << "Enter element to search for: ";
    cin >> key;
    list.SearchElement(key);
    
    list.printList();
    
    return 0;
}
