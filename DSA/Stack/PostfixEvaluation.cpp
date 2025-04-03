#include<iostream>
#include<string>
using namespace std;

class Stack{
    public:
        int * stack;
        int size;
        int top;
        Stack(int capacity){
            size = capacity;
            stack = new int[size];
            top = -1;        
        }
          void push(int value) {
        if (top < size - 1) {
            stack[++top] = value;
        } else {
            cout << "Error: Stack overflow" << endl;
        }
    }
       int pop() {
        if (top >= 0) {
            return stack[top--];
        } else {
            cout << "Error: Stack underflow" << endl;
            return -1;  // Return a special value indicating underflow
        }
    }
        void PostFixEvaluation(string postfix,int N ){
            if(top==N-1){
                return ;
            }
            for(int i=0;i<N;i++){
                if(isdigit(postfix[i])){
                    push(postfix[i]-'0');
        
                }
                else{
                    
                    int op2 = pop();
                    int op1 = pop();
                    push(op1<i>op2);
                    // cout<<stack[top]<<" ";
                }}
                    cout<<stack[top]<<" ";
       
}
        
        
};


int main(){
    string postfix = "59+84-*85-94-+/";
    int N = postfix.size() ;       
    Stack s1(N);
    s1.PostFixEvaluation(postfix, N );
    // s1.top_Ele(N);
    return 0 ; 
}