#include<iostream>
#include<vector>
using namespace std ;
class Stack{
    public:
        int *stack;
        int top;
    int capacity;

    public:
        Stack(int size){
            capacity = size;
            stack = new int[capacity];
            top=-1;
        }
    void insert(vector<int>&arr1,int n){
        for(int i=0;i<arr1.size();i++){
        if(top==n-1){
            cout<<"Stack Overflow ";
            return ;
        }
       
        stack[++top] = arr1[i];
    }
    for(int i=top;i>=0;i--){
        if(top==-1){
            cout<<"Stack is empty ";
            return ;
        }
        cout<<stack[i]<<"  ";
        
    }

    }

};
int main(){
    vector<int>arr1 = {2,3,4,6,5};
    int N = arr1.capacity();
    Stack s1(N);
    s1.insert(arr1,N);
    return 0;
}