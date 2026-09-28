#include <iostream>
using namespace std;

struct Node {
    string song;
    Node *prev, *next;
};

Node *head = NULL;

void addFront(string s) {
    Node *n = new Node{s, NULL, head};
    if (head != NULL)
        head->prev = n;
    head = n;
}

void addEnd(string s) {
    Node *n = new Node{s, NULL, NULL};

    if (head == NULL) {
        head = n;
        return;
    }

    Node *p = head;
    while (p->next != NULL)
        p = p->next;

    p->next = n;
    n->prev = p;
}

void insertAfter(string key, string s) {
    Node *p = head;

    while (p != NULL && p->song != key)
        p = p->next;

    if (p == NULL) {
        cout << "Song not found\n";
        return;
    }

    Node *n = new Node{s, p, p->next};

    if (p->next != NULL)
        p->next->prev = n;

    p->next = n;
}

void deleteFront() {
    if (head == NULL) {
        cout << "Playlist is empty\n";
        return;
    }

    Node *p = head;
    head = head->next;

    if (head != NULL)
        head->prev = NULL;

    delete p;
}

void display() {
    Node *p = head;

    cout << "Playlist: ";
    while (p != NULL) {
        cout << p->song << " ";
        p = p->next;
    }
    cout << endl;
}

void countSongs() {
    int count = 0;
    Node *p = head;

    while (p != NULL) {
        count++;
        p = p->next;
    }

    cout << "Total Songs: " << count << endl;
}

int main() {
    addFront("Song1");
    display();

    addEnd("Song3");
    display();

    insertAfter("Song1", "Song2");
    display();

    countSongs();

    deleteFront();
    display();

    countSongs();

    return 0;
}