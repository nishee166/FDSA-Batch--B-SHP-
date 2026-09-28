#include <iostream>
using namespace std;

struct Node {
    string page;
    Node *next;
};

Node *top = NULL;

void visit(string page) {
    Node *n = new Node{page, top};
    top = n;
    cout << "Current Page: " << top->page << endl;
}

void back() {
    if (top == NULL) {
        cout << "No history\n";
        return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;

    if (top != NULL)
        cout << "Current Page: " << top->page << endl;
    else
        cout << "No history\n";
}

int main() {
    visit("Google");
    visit("YouTube");
    visit("GitHub");

    back();
    back();
    back();
    back();

    return 0;
}