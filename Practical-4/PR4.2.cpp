#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};

class LinkedList
{
    Node *head;

public:
    LinkedList()
    {
        head = NULL;
    }

    
    void insertEnd(int value)
    {
        Node *newNode = new Node(value);

        if (head == NULL)
        {
            head = newNode;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    
    void deleteByValue(int value)
    {
        if (head == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        
        if (head->data == value)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node *temp = head;

        while (temp->next != NULL &&
               temp->next->data != value)
        {
            temp = temp->next;
        }

        
        if (temp->next == NULL)
        {
            cout << "Patient token not found\n";
            return;
        }

        Node *deleteNode = temp->next;
        temp->next = deleteNode->next;
        delete deleteNode;
    }

    
    void display()
    {
        Node *temp = head;

        if (head == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }

    
    void reversePrint(Node *temp)
    {
        if (temp == NULL)
            return;

        reversePrint(temp->next);
        cout << temp->data << " ";
    }

    void displayReverse()
    {
        if (head == NULL)
        {
            cout << "Queue is empty\n";
            return;
        }

        reversePrint(head);
        cout << endl;
    }
};

int main()
{
    LinkedList queue;
    int n, value, deleteValue;

    cout << "Enter number of patients: ";
    cin >> n;

    cout << "Enter patient tokens:\n";

    for (int i = 0; i < n; i++)
    {
        cin >> value;
        queue.insertEnd(value);
    }

    cout << "\nQueue from front to back: ";
    queue.display();

    cout << "Enter patient token to delete: ";
    cin >> deleteValue;

    queue.deleteByValue(deleteValue);

    cout << "\nQueue after deletion: ";
    queue.display();

    cout << "Queue from last to first: ";
    queue.displayReverse();

    return 0;
}