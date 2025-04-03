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

node * search(node * temp ,int x){
    if(temp==nullptr){
        cout<<"Number does not found "<<x<<endl;
        return nullptr;
    }
    if(x==temp->data){
        cout<<"Matched number is:"<<x<<endl;

        return temp;
    }
    else{
        if(x<temp->data){
            cout<<"Searching in left side: "<<endl;
            return search(temp->left , x);
        }
        else{
            cout<<"Searching in right side:"<<endl;
            return  search(temp->right  , x);
        }
    
    }
    
}
node * postorder(node * temp){
    if(temp==nullptr){
        return nullptr;
    }
    temp->left= postorder(temp->left);
    temp->right= postorder(temp->right);
    cout<<temp->data<<" ";
}

node*  deletion(node * temp,int x){
    if(temp==nullptr){
        cout<<"Number not found in the tree "<<x<<endl;;
        return nullptr;
        
    }
    if(x<temp->data){
        temp->left = deletion(temp->left,x);
    }
    else if(x>temp->data){
        temp->right = deletion(temp->right,x);
    }
    else{
        if(temp->left==nullptr){
            node * T_temp = temp->right;
            delete temp;
            return T_temp;
        }
        else{
            node * T_temp = temp->left;
            delete temp;
            return T_temp;
        }
    }
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
    cout<<"Before deleting the node: ";
    inorder(root);
    cout<<endl;
    search(root , 43);
    cout<<"After deleting the specific node: "<<endl;
    deletion(root , 98);
    // cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);

    return 0;
}