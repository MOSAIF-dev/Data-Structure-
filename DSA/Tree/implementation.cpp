#include<iostream>
#include<queue>
using namespace std;

class Nodes{
    public:
    Nodes * left ;
    int data;
    Nodes *right ; 
    
    Nodes(int val){
        data = val ;
        left = right = nullptr;
    }

};




int main(){
    int x ,num1 , num2;
    
    cout<<"Enter your root data ";
    cin>>x;
    queue<Nodes*>q ;
    Nodes *root = new Nodes(x);

    q.push(root);


    //Build the Binary tree .

    while(!q.empty()){
        //Create left or right children  .
        Nodes * temp  = q.front();
        q.pop();
        cout<<"Enter the value of left child data "<<temp->data<<" :";

        cin>>num1;
        if(num1!=-1){
            
            temp->left = new Nodes(num1);
            q.push(temp->left);
        }

        cout<<"Enter your right child  data "<<temp->data<<" : ";
        cin>>num2;

        if(num2!=-1){
            temp->right = new Nodes(num2);
            q.push(temp->right);
        }


    }
    return 0;
}