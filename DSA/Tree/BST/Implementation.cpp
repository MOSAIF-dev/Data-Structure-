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

node * insert(node * temp , int x){
    if(temp==nullptr){
        return temp = new node (x);
    }
    if(x<temp->data){
       temp->left =  insert(temp->left , x);
    }
    else{
        temp->right = insert(temp->right,x);
    }

    return temp;
}

void inorder(node * temp){
    if(temp==nullptr){
        return ;
    }
   inorder(temp->left);
    cout<<temp->data<<" ";
   inorder(temp->right);
    
}
int main(){
    node * root = nullptr ;
    root = insert(root , 75);
    root = insert(root , 70);
    root = insert(root , 44);
    root = insert(root , 48);
    root = insert(root , 98);
    root = insert(root , 108);
    root = insert(root , 91);
    root = insert(root , 145);
    inorder(root);
    return 0;
}