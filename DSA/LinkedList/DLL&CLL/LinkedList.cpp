#include<iostream>
using namespace std;

class node {
public:
    int data;
    node *prev;
    node *next;

    node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

class DLinkedList {
private:
    node *head;

public:
    DLinkedList() {
        head = nullptr;
    }

    void insertAtEnd(int x) {
        node *temp = new node(x);
        if (head == nullptr) {
            head = temp;
        } else {
            node *p = head;
            while (p->next != nullptr) {
                p = p->next;
            }
            p->next = temp;
            temp->prev = p;
        }
    }

    void insertAtBegin(int x){
        node * temp = new node(x);
        if(head==nullptr){
            head = temp;
        }
        else{
            
    
            temp->next = head;
            head->prev = temp;
            head = temp;

        }
    }
    void display() {
        node *temp = head;
        if (temp == nullptr) {
            cout << "The list is empty!" << endl;
            return;
        }
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
    void RemoveFomBegin(){
        node* temp = head ;
        if(temp==nullptr){
            cout<<"No Linked List Exist ";
            return ;
        }
        else{
           head = temp->next;
           if(head!=nullptr){
            head->prev = nullptr;
           }
            delete temp;
            
           
        }

    }


    void RemoveFromEnd(){
        node * temp = head; 
        if(head==nullptr){
            cout<<"No linked List Exist";
            return ;
        }
        if(head->next==nullptr){
            delete head;
            head  = nullptr;
        }
        else{
            // node * p = head;
            while(temp->next!=nullptr){
                temp = temp->next;
            }
            temp->prev->next = nullptr;
            delete temp;
        }
    }
};

int main() {
    DLinkedList list;
    int x, num;

    cout << "Enter the number of nodes you want to insert: ";
    cin >> x;

    cout << "Enter your node data: ";
    for (int i = 0; i < x; i++) {
        cin >> num;
        // list.insertAtEnd(num);
        list.insertAtBegin(num);
    }

    cout << "The linked list is: ";
    // list.RemoveFomBegin();
    list.RemoveFromEnd();
    list.display();
    
    return 0;
}
