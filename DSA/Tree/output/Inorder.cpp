#include<iostream>
using namespace std;

class node {
public:
    node *left;
    int data;
    node *right;
    node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to build the binary tree
node *BinaryTree() {
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    }
    node *temp = new node(x);
    
    cout << "Enter your left child data of " << x << ": ";
    temp->left = BinaryTree();
    
    cout << "Enter your right child data of " << x << ": ";
    temp->right = BinaryTree();
    
    return temp;
}

// In-order traversal to print the tree
void In_Order_Traversal(node *root) {
    if (root == nullptr) {
        return;
    }
    
    // First traverse the left subtree
    In_Order_Traversal(root->left);
    
    // Then print the root node data
    cout << root->data << " ";
    
    // Finally traverse the right subtree
    In_Order_Traversal(root->right);
}

// Pre-order traversal to print the tree
void Pre_Order_Traversal(node *root) {
    if (root == nullptr) {
        return;
    }
    
    // Then print the root node data
    cout << root->data << " ";
    
    // First traverse the left subtree
    Pre_Order_Traversal(root->left);
    
    // Finally traverse the right subtree
    Pre_Order_Traversal(root->right);
}

// Post-order traversal to print the tree
void Post_Order_Traversal(node *root) {
    if (root == nullptr) {
        return;
    }
    
    // First traverse the left subtree
    Post_Order_Traversal(root->left);
    
    // Then traverse the right subtree
    Post_Order_Traversal(root->right);
    
    // Finally print the root node data
    cout << root->data << " ";
}

int main() {
    cout << "Enter your root data: ";
    node *root = BinaryTree();
    
    cout << "In-order traversal of the tree: ";
    In_Order_Traversal(root);
    cout << endl;
    
    cout << "Pre-order traversal of the tree: ";
    Pre_Order_Traversal(root);
    cout << endl;
    
    cout << "Post-order traversal of the tree: ";
    Post_Order_Traversal(root);
    cout << endl;

    return 0;
}
