#include<iostream>
using namespace std ;

class node{
    public:
    node * left;
    int data;
    node *right;
    node(int val){
        data = val;
        left = right = nullptr;
    }
};

node * insert()
{
    int x;
    cin>>x ; 
    if(x==-1){
        return nullptr;
    }
    node * temp = new node(x);
    cout<<"Enter your left child data: "<<x<<":";
    temp->left=insert();
    cout<<"Enter your right  child data: "<<x<<":";
    temp->right = insert() ;
    return temp;
}

int  leafnode(node * t){
    if(t==nullptr){
        return 0;
    }
    if(t->left == nullptr && t->right==nullptr){
        return 1;
    }
    else{
        return (leafnode(t->left)) + (leafnode(t->right));
    }
}

int internalNode(node* t) {
    if (t == nullptr) {
        return 0;
    }
    
    if (t->left== nullptr && t->right== nullptr) {
        return 0;  }
     else {
        return 1 + (internalNode(t->left) + (internalNode(t->right))); 
    }
}

int Tnode(node * t){
    if(t==nullptr){
        return 0;
    }
    if(t->left==nullptr && t->right==nullptr){
        return 1;
    }
    else{
        return 1+(Tnode(t->left) + Tnode(t->right));
    }
}

int height(node * t){
    if(t==nullptr){
        return 0;
    }
    if(t->left==nullptr && t->right ==nullptr){
        return 0;
    }
    else{
        int l = height(t->left);
        int r = height(t->right);
        return 1+max(l,r);
    }
}

int level(node * t){
    if(t==nullptr){
        return 0;
    }
    if(t->left && t->right == nullptr){
        return 1;
    }
    else { 
        int l = level(t->left);
        int r = level(t->right);
        return 1 + max(l,r);
    }
}
int main(){

    cout<<"Enter your root node data: ";
    node * root = insert();
    int count  = leafnode(root);
    cout<<"Number of leaf node: "<<count<<endl;
    int count_1 = internalNode(root);
    cout<<"Number of the internal: "<<count_1<<endl;
    int Count_2 = Tnode(root);
    cout<<"Number of total Node: "<<Count_2;
    int h =  height(root);
    cout<<"\nTotal height of the tree is: "<<h;
    int l = level(root);
    cout<<"\nTotal level of the tree: "<<l;
    return 0;
}