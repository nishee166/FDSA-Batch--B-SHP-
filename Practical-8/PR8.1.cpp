#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* createTree(int n) {
    if (n == 0)
        return nullptr;

    int value;
    cout << "Enter root value: ";
    cin >> value;

    Node* root = new Node(value);
    queue<Node*> q;
    q.push(root);

    int count = 1;

    while (count < n) {
        Node* current = q.front();
        q.pop();

        cout << "Enter left child of " << current->data << ": ";
        cin >> value;
        current->left = new Node(value);
        q.push(current->left);
        count++;

        if (count < n) {
            cout << "Enter right child of " << current->data << ": ";
            cin >> value;
            current->right = new Node(value);
            q.push(current->right);
            count++;
        }
    }

    return root;
}

void inorder(Node* root) {
    if (root == nullptr)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == nullptr)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == nullptr)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

void levelOrder(Node* root) {
    if (root == nullptr)
        return;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* current = q.front();
        q.pop();

        cout << current->data << " ";

        if (current->left != nullptr)
            q.push(current->left);

        if (current->right != nullptr)
            q.push(current->right);
    }
}

int main() {
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    Node* root = createTree(n);

    cout << "\nInorder: ";
    inorder(root);

    cout << "\nPreorder: ";
    preorder(root);

    cout << "\nPostorder: ";
    postorder(root);

    cout << "\nLevel Order: ";
    levelOrder(root);

    return 0;
}