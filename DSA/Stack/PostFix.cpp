#include<iostream>
#include<string>
#include<cmath> // For pow function
using namespace std;

class Stack {
public:
    int *stack;
    int size;
    int top;

    Stack(int capacity) {
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
            return -1;
        }
    }

    void PostFixEvaluation(string postfix, int N) {
        for (int i = 0; i < N; i++) {
            if (isdigit(postfix[i])) {
                push(postfix[i] - '0');
            } else {
                int op2 = pop();
                int op1 = pop();

                if (postfix[i] == '+') {
                    push(op1 + op2);
                } else if (postfix[i] == '-') {
                    push(op1 - op2);
                } else if (postfix[i] == '*') {
                    push(op1 * op2);
                } else if (postfix[i] == '/') {
                    if (op2 != 0) {
                        push(op1 / op2);
                    } else {
                        cout << "Error: Division by zero!" << endl;
                        return;
                    }
                } 
            }
        }
        cout << "Final result: " << stack[top] << endl;
    }
};

int main() {
    string postfix = "59+84-*85-94-+/";  // Postfix expression with the '↑' symbol for exponentiation
    int N = postfix.size();
    Stack s1(N);
    s1.PostFixEvaluation(postfix, N);
    return 0;
}
