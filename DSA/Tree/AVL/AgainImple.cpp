#include<iostream>
using namespace std;

class node {
public:
    node* left;
    int data;
    node* right;
    int height;

    // Constructor to initialize a node
    node(int val) {
        data = val;
        left = right = nullptr;
        height = 1; // Height starts as 1 for a new node (leaf node)
    }
};

// Function to insert a node into the BST
node* insert(node* temp, int x) {
    // If the current node is null, create a new node
    if (temp == nullptr) {
        return new node(x);
    }

    // If the value is less than the current node's data, insert it in the left subtree
    if (x < temp->data) {
        temp->left = insert(temp->left, x);
    }
    // If the value is greater than the current node's data, insert it in the right subtree
    else if (x > temp->data) {
        temp->right = insert(temp->right, x);
    }

    // Return the node pointer
    return temp;
}

int Height(node * temp){
    if(temp==nullptr){
        return 0;
    }
    if(temp->left==nullptr && temp->right==nullptr){
        return 0;
    }
        return 1+max(Height(temp->left),(Height(temp->right)));
    }

int balanceFactor(node* temp){
    if(temp==nullptr){
        return 0;
    }
    return Height(temp->left)-Height(temp->right);
}
node* leftRotation(node *temp) {
    // Step 1: Set `y` to be the right child of `temp`
    node* y = temp->right;

    // Step 2: Make `y`'s left child as the right child of `temp`
    temp->right = y->left;

    // Step 3: Make `temp` as the left child of `y`
    y->left = temp;

    // Step 4: Update heights of `temp` and `y`
    temp->height = max(Height(temp->left), Height(temp->right)) + 1;
    y->height = max(Height(y->left), Height(y->right)) + 1;

    // Step 5: Return `y` as the new root of the subtree
    return y;
}

void inorder(node* temp) {
    if (temp == nullptr) {
        return;  
    }

  
    inorder(temp->left);

    
    cout << temp->data << " ";

   
    inorder(temp->right);
}

int main() {
    int val;
    cout << "Enter how many nodes to insert: ";
    cin >> val;

    int data;
    node* root = nullptr;

    cout << "Enter the data for the nodes: ";
    // Insert the nodes one by one
    for (int i = 0; i < val; i++) {
        cin >> data;
        root = insert(root, data);  
    }

    
    cout << "Inorder traversal of the BST: ";
    inorder(root);
    cout << endl;
    // cout<<"BST tree Height: ";
    int height = Height(root);
    cout<<"BST tree Height: "<<height<<endl;
    int balancy =  balanceFactor(root);
    
    cout<<"Balance of the tree: "<<balancy;
    return 0;
}
