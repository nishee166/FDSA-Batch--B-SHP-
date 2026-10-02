#include <iostream>
using namespace std;

class Queue {
    struct Node {
        string patient;
        Node* next;
    };

    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void arrive(string name) {
        Node* newNode = new Node;
        newNode->patient = name;
        newNode->next = nullptr;

        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Front patient: " << front->patient << endl;
    }

    void attend() {
        if (front == nullptr) {
            cout << "Error: No patients waiting" << endl;
            return;
        }

        cout << "Attended patient: " << front->patient << endl;

        Node* temp = front;
        front = front->next;
        delete temp;

        if (front == nullptr)
            rear = nullptr;

        if (front != nullptr)
            cout << "Front patient: " << front->patient << endl;
        else
            cout << "Queue is empty" << endl;
    }

    void display() {
        if (front == nullptr) {
            cout << "Queue is empty" << endl;
            return;
        }

        Node* temp = front;

        cout << "Patients: ";

        while (temp != nullptr) {
            cout << temp->patient << " ";
            temp = temp->next;
        }

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice;
    string name;

    do {
        cout << "\n1. Arrive";
        cout << "\n2. Attend";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter patient name: ";
            cin >> name;
            q.arrive(name);
            break;

        case 2:
            q.attend();
            break;

        case 3:
            q.display();
            break;

        case 4:
            cout << "Program ended." << endl;
            break;

        default:
            cout << "Invalid choice." << endl;
        }

    } while (choice != 4);

    return 0;
}