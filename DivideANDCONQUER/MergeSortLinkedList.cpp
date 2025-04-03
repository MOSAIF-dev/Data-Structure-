#include<iostream>

using namespace std ;

//  Merge Sort on the Linked list  .....


//  Logic kya h baba ? 
//  Ans - 1. First Find the Mid Node of the Linked List O(n) 
//  Uses two pointer technique to represent the head and mid->next node .

//  2. Then Split the Linked List into two halves O(n)
//  3. Then Recursively call the Merge Sort on both halves O(n log n)
//  4. Then Merge the two sorted halves O(n)
//  5. Return the head of the sorted Linked List O(1)
//  Time Complexity - O(n log n)

// class MergeSort_LinkedList{
//     private :
    
// };

class Node{
    public:
    int data ;
    Node* next ;
    Node(int value){
        data = value ;
        next = NULL ;
        }
    
};

class LinkedList{
    public :
    Node* head ;
    LinkedList(){
        head = NULL ;
        }

    void Insert(int data) 
    {
        node * new_node = new node (data);
        if(head==nullptr){
            head = new_node ;
        }
        else{
            node * temp = head ; // Dummy Node to iterate the linked list till End it will take O(n) time.
            while(temp->next != nullptr){
                temp = temp->next ;
                }
                temp->next = new_node ;
                }
    }

    void MergeSort(head){
        if(head==nullptr || head->next==nullptr){
            return head ; // No need to apply Merge Sort on a single node or empty linked list
        }
        else{
          
            MergeSort(head);
            MergeSort(head2);
            //  Conquer the two halves it will take O(n) time
            merge(head,mid,head2);

        }
    }
    void Merge(node *head1, node * mid , node * head2){
        node * current = head1 ;
        node * current2 = head2 ;
        while(current->next != mid && current2->next != nullptr){
            current = current->next ;
            current2 = current2->next ;
            }
            current->next = current2 ;
            

    }
};



int main(){
        
    return 0;
}



#include<iostream>

using namespace std;

//  Merge Sort on the Linked list ..... 

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
public:
    Node* head;
    LinkedList() {
        head = nullptr;
    }

    // Function to insert a new node at the end of the linked list
    void Insert(int data) {
        Node* new_node = new Node(data);
        if (head == nullptr) {
            head = new_node;
        } else {
            Node* temp = head;  // Temporary pointer to traverse the linked list
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }

    // Function to find the middle of the linked list
    Node* findMiddle(Node* start) {
        if (start == nullptr) return nullptr;
        Node* slow = start;
        Node* fast = start;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow; // slow pointer will be at the middle of the list
    }

    // Function to merge two sorted linked lists
    Node* merge(Node* left, Node* right) {
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        
        // Merge sorted linked lists
        if (left->data <= right->data) {
            left->next = merge(left->next, right);
            return left;
        } else {
            right->next = merge(left, right->next);
            return right;
        }
    }

    // Function to perform merge sort on the linked list
    Node* mergeSort(Node* start) {
        if (start == nullptr || start->next == nullptr) {
            return start;  // Base case: a list with 0 or 1 element is already sorted
        }

        // Step 1: Find the middle of the list
        Node* middle = findMiddle(start);

        // Step 2: Split the list into two halves
        Node* left = start;
        Node* right = middle->next;
        middle->next = nullptr;  // Break the list into two halves

        // Step 3: Recursively sort both halves
        left = mergeSort(left);
        right = mergeSort(right);

        // Step 4: Merge the two sorted halves
        return merge(left, right);
    }

    // Function to sort the entire linked list using merge sort
    void sort() {
        head = mergeSort(head);
    }

    // Function to print the linked list
    void printList() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    
    // Inserting elements into the linked list
    list.Insert(5);
    list.Insert(3);
    list.Insert(8);
    list.Insert(1);
    list.Insert(2);

    cout << "Original List: ";
    list.printList();

    // Sorting the linked list using merge sort
    list.sort();

    cout << "Sorted List: ";
    list.printList();

    return 0;
}
