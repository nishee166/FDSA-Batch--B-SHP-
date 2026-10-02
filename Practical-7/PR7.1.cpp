#include <iostream>
using namespace std;

class Queue {
    int queue[5];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    void join(int token) {
        if (rear == 4) {
            cout << "Error: Queue is full" << endl;
            return;
        }

        if (front == -1)
            front = 0;

        rear++;
        queue[rear] = token;

        cout << "Front token: " << queue[front] << endl;
    }

    void serve() {
        if (front == -1 || front > rear) {
            cout << "Error: Queue is empty" << endl;
            return;
        }

        cout << "Served token: " << queue[front] << endl;
        front++;

        if (front > rear) {
            front = -1;
            rear = -1;
            cout << "Queue is empty" << endl;
        } else {
            cout << "Front token: " << queue[front] << endl;
        }
    }

    void display() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return;
        }

        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";

        cout << endl;
    }
};

int main() {
    Queue q;
    int choice, token;

    do {
        cout << "\n1. Join";
        cout << "\n2. Serve";
        cout << "\n3. Display";
        cout << "\n4. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter token: ";
            cin >> token;
            q.join(token);
            break;

        case 2:
            q.serve();
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