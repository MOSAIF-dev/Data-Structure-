#include <iostream>
#include <stack>
#include <algorithm>
#include <cctype>

using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-') {
        return 1;
    }
    if (op == '*' || op == '/') {
        return 2;
    }
    return 0;
}

string infixToPrefix(string infix) {
    reverse(infix.begin(), infix.end());
    
    stack<char> operators;
    string result = "";
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        if (isalnum(c)) {
            result += c;
        }
        else if (c == ')') {
            operators.push(c);
        }
        else if (c == '(') {
            while (!operators.empty() && operators.top() != ')') {
                result += operators.top();
                operators.pop();
            }
            operators.pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/') {
            while (!operators.empty() && precedence(operators.top()) >= precedence(c)) {
                result += operators.top();
                operators.pop();
            }
            operators.push(c);
        }
    }
    
    while (!operators.empty()) {
        result += operators.top();
        operators.pop();
    }
    
    reverse(result.begin(), result.end());
    
    return result;
}

int main() {
    string infix = "(A-B/C)*(A/K-L)";
    
    cout << "Infix Expression: " << infix << endl;
    string prefix = infixToPrefix(infix);
    cout << "Prefix Expression: " << prefix << endl;
    
    return 0;
}
