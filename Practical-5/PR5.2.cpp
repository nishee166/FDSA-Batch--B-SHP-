#include <iostream>
using namespace std;

struct Node {
    string name;
    Node *next;
};

Node *head = NULL;

void insertEnd(string name) {
    Node *n = new Node{name, NULL};

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node *p = head;

    while (p->next != head)
        p = p->next;

    p->next = n;
    n->next = head;
}

void insertFront(string name) {
    Node *n = new Node{name, NULL};

    if (head == NULL) {
        head = n;
        n->next = head;
        return;
    }

    Node *p = head;

    while (p->next != head)
        p = p->next;

    n->next = head;
    p->next = n;
    head = n;
}

void insertAt(string name, int pos) {
    if (pos <= 1) {
        insertFront(name);
        return;
    }

    if (head == NULL)
        return;

    Node *p = head;

    for (int i = 1; i < pos - 1 && p->next != head; i++)
        p = p->next;

    Node *n = new Node{name, p->next};
    p->next = n;
}

void deleteAt(int pos) {
    if (head == NULL) {
        cout << "Circle is empty\n";
        return;
    }

    if (pos <= 1) {
        if (head->next == head) {
            delete head;
            head = NULL;
            return;
        }

        Node *p = head;

        while (p->next != head)
            p = p->next;

        Node *temp = head;
        head = head->next;
        p->next = head;

        delete temp;
        return;
    }

    Node *p = head;

    for (int i = 1; i < pos - 1 && p->next != head; i++)
        p = p->next;

    if (p->next == head) {
        cout << "Position not found\n";
        return;
    }

    Node *temp = p->next;
    p->next = temp->next;
    delete temp;
}

void display() {
    if (head == NULL) {
        cout << "Circle is empty\n";
        return;
    }

    Node *p = head;

    cout << "Circle: ";

    do {
        cout << p->name << " ";
        p = p->next;
    } while (p != head);

    cout << endl;
}

int main() {
    insertEnd("A");
    display();

    insertEnd("B");
    display();

    insertEnd("C");
    display();

    insertFront("D");
    display();

    insertAt("E", 3);
    display();

    deleteAt(2);
    display();

    deleteAt(1);
    display();

    return 0;
}