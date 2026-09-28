#include <iostream>
using namespace std;

int stack[5], top = -1;

void push(int x) {
    if (top == 4)
        cout << "Stack Overflow\n";
    else {
        stack[++top] = x;
        cout << "Top: " << stack[top] << endl;
    }
}

void pop() {
    if (top == -1)
        cout << "Stack Underflow\n";
    else {
        cout << "Removed: " << stack[top--] << endl;
        if (top != -1)
            cout << "Top: " << stack[top] << endl;
        else
            cout << "Stack Empty\n";
    }
}

int main() {
    push(10);
    push(20);
    push(30);
    pop();
    pop();
    pop();
    pop();

    return 0;
}