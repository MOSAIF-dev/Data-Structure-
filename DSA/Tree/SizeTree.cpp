#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Nodes {
public:
    Nodes *left;
    int data;
    Nodes *right;

    Nodes(int val) {
        data = val;
        left = right = nullptr;
    }
};

int main() {
    int x, num1, num2;

    cout << "Enter your root data: ";
    cin >> x;
    vector<int> ans;
    int count=0;
    Nodes *root = new Nodes(x);
    queue<Nodes*> q;
    q.push(root);

    // Build the Binary Tree.
    while (!q.empty()) {
        Nodes *temp = q.front();
        q.pop();

        cout << "Enter the value of left child for node " << temp->data << ": ";
        cin >> num1;
        if (num1 != -1) {
            temp->left = new Nodes(num1);
            q.push(temp->left);
        }

        cout << "Enter the value of right child for node " << temp->data << ": ";
        cin >> num2;
        if (num2 != -1) {
            temp->right = new Nodes(num2);
            q.push(temp->right);
        }
    }

    // Now that the tree is built, let's do level-order traversal.
    queue<Nodes*> q2;
    q2.push(root);

    while (!q2.empty()) {
        Nodes *temp1 = q2.front();
        q2.pop();
        ans.push_back(temp1->data);

        if (temp1->left) {
            q2.push(temp1->left);
        }
        if (temp1->right) {
            q2.push(temp1->right);
        }
    }

    // Print the level-order traversal.
    cout << "Level-order traversal of the tree: ";
    for (int i : ans) {
        cout << i << " ";
        count++;
    }
    cout << endl;

    cout<<"Count or Tree Size: "<<count<<endl;
    return 0;
}
