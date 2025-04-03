#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *prev;
    node *next;
public:
    node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DLL {
private:
    node* head;
    node* tail;

public:
    DLL() {
        head = tail = nullptr;
    }

    void insert(int x) {
        node* temp = new node(x);  // Create a new node
        if (head == nullptr) {      // If the list is empty
            head = tail = temp;     // Set both head and tail to the new node
        } else {
            temp->next = head;      // New node's next points to the current head
            head->prev = temp;      // Current head's prev points to the new node
            head = temp;            // Move the head pointer to the new node
        }
    }

    void display() {
        node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }

    void Palindrome(){
        node * temp ;
        if(head==nullptr){
            cout<<"List is empty"<<endl;
        }
        else if(head->next==nullptr){
            cout<<"List has only one element: "<<head->data<<endl;
        }
        else{
            node *slow ;
            node *fast= head;
            temp= head;
            while(temp!=nullptr){
                temp=temp->next;
            }
            
            while(fast->next->next!=nullptr){
                slow = fast;
                fast = fast->next;
                if(slow->data==temp->data){
                    cout<<"Palindrome "<<temp->data<<"  "<<slow->data<<"  "<<endl;
                    temp = temp->prev;
                }
            }
        }
    }
};

int main() {
    DLL dll;

    // Test insertions
    dll.insert(10);
    dll.insert(20);
    dll.insert(10);

    // Display the list
    dll.Palindrome();
    dll.display();  // Expected output: 30 20 10 

    return 0;
}
