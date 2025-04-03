#include <iostream>
#include <stack>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

class ExpressionEvaluator {
public:
    int evaluatePostfix(const string& expr) {
        stack<int> s;
        
        for (char ch : expr) {
            if (isdigit(ch)) {
                s.push(ch - '0');  // Convert char to int and push to stack
            } else if (isOperator(ch)) {
                int operand2 = s.top(); s.pop();
                int operand1 = s.top(); s.pop();
                int result = performOperation(operand1, operand2, ch);
                s.push(result);
            }
        }
        return s.top();
    }

    int evaluatePrefix(const string& expr) {
        stack<int> s;

        // Process the prefix expression from right to left
        for (int i = expr.length() - 1; i >= 0; --i) {
            char ch = expr[i];
            if (isdigit(ch)) {
                s.push(ch - '0');
            } else if (isOperator(ch)) {
                int operand1 = s.top(); s.pop();
                int operand2 = s.top(); s.pop();
                int result = performOperation(operand1, operand2, ch);
                s.push(result);
            }
        }
        return s.top();
    }

private:
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/');
    }

    int performOperation(int operand1, int operand2, char op) {
        switch (op) {
            case '+': return operand1 + operand2;
            case '-': return operand1 - operand2;
            case '*': return operand1 * operand2;
            case '/': return operand1 / operand2;
            default: return 0;
        }
    }
};

int main() {
    ExpressionEvaluator evaluator;

    string postfix = "23*54*+9-";  // Example postfix expression
    string prefix = "-+*23*549";   // Example prefix expression

    cout << "Postfix evaluation: " << evaluator.evaluatePostfix(postfix) << endl;
    cout << "Prefix evaluation: " << evaluator.evaluatePrefix(prefix) << endl;

    return 0;
}
