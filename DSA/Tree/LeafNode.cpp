#include<iostream>
using namespace std;
class node{
    public:
    node * left ;
    int data;
    node * right;
    node(int val){
        data = val;
        left = right = nullptr;
    }
};


node * insert(){
    int x;
    cin>>x;
   if(x==-1){
    return nullptr;
   }
   node * temp = new node(x);
    cout<<"Enter your left child data "<<x<<":";
    temp->left = insert();
    cout<<"Enter your right child data "<<x<<":";

    temp->right = insert();
   return temp;

}

int leafnodeCount(node * root){
    if(root==nullptr){
        return 0;
    }
    if(root->left==nullptr && root->right==nullptr){
        return 1;
    }
    else{
        return (leafnodeCount(root->left))+(leafnodeCount(root->right));
    }

}


int main(){
    
    cout<<"Enter your root node data: ";
    node * root = insert();
    int leafnode = leafnodeCount(root);
    cout<<"Total Count of Leafnode: "<<leafnode;
    return 0;
}