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

class ClinkedList {
public:
    node* head;

    ClinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int data) {
        node* temp = new node(data);

        if (head == nullptr) {
            head = temp;
            temp->next = head;  // Points to itself, circular link
        } else {
            node* p = head;
            while (p->next != head) {  // Find the last node
                p = p->next;
            }
            p->next = temp;  // Add new node after the last node
            temp->next = head;  // Points back to head, keeping it circular
        }
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }

        node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    void Search() {
        int data;
        cout << "Enter the data to be searched: ";
        cin >> data;
        node* temp = head;
        if (head == nullptr) {
            cout << "No linked list exists!" << endl;
            return;
        }

        int i = 0;
        do {
            if (temp->data == data) {
                cout << "Data found at position " << (i + 1) << endl;
                return;
            }
            temp = temp->next;
            i++;
        } while (temp != head);

        cout << "Data not found!" << endl;
    }

    void removeEle(int x) {
        if (head == nullptr) {
            cout << "Linked List is empty!" << endl;
            return;
        }

        node* temp = head;

        // If the node to be deleted is the head node
        if (temp->data == x) {
            // If there's only one node in the list
            if (temp->next == head) {
                cout << x << " data is removed from the linked list!" << endl;
                delete temp;
                head = nullptr;
                return;
            }

            // More than one node in the list
            node* p = head;
            while (p->next != head) {
                p = p->next;
            }
            head = head->next;
            p->next = head;
            delete temp;
            cout << x << " data is removed from the linked list!" << endl;
            return;
        }

        // Deleting node that is not the head node
        node* prev = nullptr;
        temp = head;
        do {
            if (temp->data == x) {
                prev->next = temp->next;
                delete temp;
                cout << x << " data is removed from the linked list!" << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        cout << "Data not found in the list!" << endl;
    }
};

int main() {
    ClinkedList list;
    int n;
    cout << "Enter your linked-list size: ";
    cin >> n;
    cout << "Enter your nodes data: ";
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        list.insertAtEnd(num);
    }

    list.display();
    list.Search();

    int removeData;
    cout << "Enter data to remove from the list: ";
    cin >> removeData;
    list.removeEle(removeData);
    list.display();

    return 0;
}
