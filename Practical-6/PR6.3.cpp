#include <iostream>
#include <cctype>
using namespace std;

char stack[50];
int top = -1;

int priority(char x) {
    if (x == '^') return 3;
    if (x == '*' || x == '/') return 2;
    if (x == '+' || x == '-') return 1;
    return 0;
}

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int main() {
    string exp, post = "";
    cin >> exp;

    for (char x : exp) {
        if (isalnum(x))
            post += x;

        else if (x == '(')
            push(x);

        else if (x == ')') {
            while (stack[top] != '(')
                post += pop();
            pop();
        }

        else {
            while (top != -1 && priority(stack[top]) >= priority(x))
                post += pop();
            push(x);
        }
    }

    while (top != -1)
        post += pop();

    cout << "Postfix: " << post << endl;

    return 0;
}