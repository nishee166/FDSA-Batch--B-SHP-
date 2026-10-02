#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> table[10];
    int n, code;

    cout << "Enter number of books: ";
    cin >> n;

    cout << "Enter book codes:\n";
    for (int i = 0; i < n; i++) {
        cin >> code;
        int index = code % 10;
        table[index].push_back(code);
    }

    cout << "Final shelf contents:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " : ";
        for (int code : table[i])
            cout << code << " ";
        cout << endl;
    }

    return 0;
}