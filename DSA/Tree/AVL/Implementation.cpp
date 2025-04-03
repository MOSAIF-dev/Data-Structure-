#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int key;
    Node* left;
    Node* right;
    int height;

    Node(int value) {
        key = value;
        left = right = nullptr;
        height = 1;
    }
};

class AVLTree {
private:
    Node* root;

    int height(Node* node) {
        if (node == nullptr) return 0;
        return node->height;
    }

    int balanceFactor(Node* node) {
        if (node == nullptr) return 0;
        return height(node->left) - height(node->right);
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;
        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;
        return y;
    }

    Node* balance(Node* node) {
        int balance = balanceFactor(node);
        if (balance > 1) {
            if (balanceFactor(node->left) >= 0) {
                return rightRotate(node);
            } else {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balance < -1) {
            if (balanceFactor(node->right) <= 0) {
                return leftRotate(node);
            } else {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    Node* insert(Node* node, int key) {
        if (node == nullptr) return new Node(key);
        if (key < node->key) {
            node->left = insert(node->left, key);
        } else if (key > node->key) {
            node->right = insert(node->right, key);
        } else {
            return node;
        }
        node->height = 1 + max(height(node->left), height(node->right));
        return balance(node);
    }

    Node* search(Node* node, int key) {
        if (node == nullptr || node->key == key) {
            return node;
        }
        if (key < node->key) {
            return search(node->left, key);
        }
        return search(node->right, key);
    }

public:
    AVLTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insert(root, key);
    }

    Node* search(int key) {
        return search(root, key);
    }

    void inorder(Node* node) {
        if (node == nullptr) return;
        inorder(node->left);
        cout << node->key << " ";
        inorder(node->right);
    }

    void inorder() {
        inorder(root);
        cout << endl;
    }
};

int main() {
    AVLTree tree;
    tree.insert(30);
    tree.insert(10);
    tree.insert(20);
    // tree.insert(15);
    // tree.insert(25);

    cout << "Inorder traversal of the AVL tree: ";
    tree.inorder();

    int key = 15;
    Node* result = tree.search(key);
    if (result != nullptr) {
        cout << "Node " << key << " found in the tree.\n";
    } else {
        cout << "Node " << key << " not found in the tree.\n";
    }

    key = 100;
    result = tree.search(key);
    if (result != nullptr) {
        cout << "Node " << key << " found in the tree.\n";
    } else {
        cout << "Node " << key << " not found in the tree.\n";
    }

    return 0;
}
