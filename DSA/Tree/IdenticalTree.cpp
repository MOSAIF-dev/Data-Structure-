#include<iostream>
using namespace std;


class node{
    public:
    node * left;
    int data;
    node * right;
    node(int val){
        data = val;
        left = right = nullptr;
    }
};

node * BT_1_Tree(){
    int x;
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    node * temp_1 = new node(x);
    cout<<"Enter your Tree_1_Root_Left_Child data "<<x<<":";
    temp_1->left = BT_1_Tree();
    cout<<"Enter your Tree_1_Root_right_Child data "<<x<<":";
    temp_1->right = BT_1_Tree();
    return temp_1;
}
// Function to check if two trees are identical


node * BT_2_Tree(){
    int x;
    cin>>x;
    if(x==-1){
        return nullptr;
    }
    node * temp_2 = new node(x);
    cout<<"Enter your Tree_2_Root_Left_Child data "<<x<<":";
    temp_2->left = BT_2_Tree();
    cout<<"Enter your Tree_2_Root_right_Child data "<<x<<":";
    temp_2->right = BT_2_Tree();
    return temp_2;
}
bool identical(node* Tree_1_root, node* Tree_2_root) {
    // If both trees are empty, they are identical
    if (Tree_1_root == nullptr && Tree_2_root == nullptr) {
        return true;
    }

    // If one tree is empty and the other is not, they are not identical
    if (Tree_1_root == nullptr || Tree_2_root == nullptr) {
        return false;
    }

    // Check if the current nodes' data is the same
    if (Tree_1_root->data != Tree_2_root->data) {
        return false;
    }

    // Recursively check the left and right subtrees
    return identical(Tree_1_root->left, Tree_2_root->left) && identical(Tree_1_root->right, Tree_2_root->right);
}

int main(){
    cout<<"Enter your Tree_1_Root_Data: ";
    node * Tree_1_Root_data = BT_1_Tree();
cout<<"Enter your Tree_2_Root_Data: ";
    node * Tree_2_Root_data = BT_2_Tree();
    bool flag = identical(Tree_1_Root_data,Tree_2_Root_data);

if(flag==0){
    
    cout<<"Trees are not identical bcz flag is: "<<flag;
}
else{
    cout<<"Trees are  identical bcz flag is: "<<flag;
}
    return 0;
}