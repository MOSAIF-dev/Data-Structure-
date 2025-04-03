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

node* binarytree() {
    int x;
    cin >> x;
    if (x == -1) {
        return nullptr;
    }

    node* temp = new node(x);
    cout << "Enter your left child data of " << x << ": ";
    temp->left = binarytree();
    cout << "Enter your right child data of " << x << ": ";
    temp->right = binarytree();
    return temp;
}

node* deletenode(node* temp, int x) {
    if (temp == nullptr) {
        cout << "No tree available.\n";
        return temp;
    }

    // If the value to be deleted is smaller, go left
    if (x < temp->data) {
        temp->left = deletenode(temp->left, x);
    }
    // If the value to be deleted is larger, go right
    else if (x > temp->data) {
        temp->right = deletenode(temp->right, x);
    }
    // If the node to be deleted is found
    else {
        // Node has only one child or no child
        if (temp->left == nullptr) {
            node* temp2 = temp->right;
            delete temp;
            return temp2;
        }
        else if (temp->right == nullptr) {
            node* temp2 = temp->left;
            delete temp;
            return temp2;
        }

        // Node has two children, find the inorder successor (smallest in the right subtree)
        node* temp2 = temp->right;
        while (temp2 && temp2->left != nullptr) {
            temp2 = temp2->left;
        }

        // Replace the node with the inorder successor
        temp->data = temp2->data;

        // Delete the inorder successor
        temp->right = deletenode(temp->right, temp2->data);
    }
    return temp;
}

// Inorder traversal function - prints nodes in ascending order
void inorder(node * temp){
    if(temp == nullptr) {
        return;
    }
    inorder(temp->left);  // Traverse the left subtree
    cout << temp->data << " ";  // Print the current node's data
    inorder(temp->right);  // Traverse the right subtree
}

int main() {
    cout << "Enter the root node data:\n";
    node* root = binarytree();

    cout << "\n";

    int valueToDelete;
    cout << "Enter the value to delete from the tree: ";
    cin >> valueToDelete;

    root = deletenode(root, valueToDelete);

    cout << "\n";
    cout << "Inorder traversal after deletion: ";
    inorder(root);
    cout << "\n";

    return 0;
}
