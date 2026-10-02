#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of student IDs: ";
    cin >> n;

    cout << "Enter student IDs:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;

        int h1 = id % 10;
        int h2 = 7 - (id % 7);
        int index = h1;
        int count = 0;

        while (table[index] != -1 && count < 10) {
            index = (h1 + (count + 1) * h2) % 10;
            count++;
        }

        if (count < 10)
            table[index] = id;
        else
            cout << "Hash table is full\n";
    }

    cout << "Final hash table:\n";
    for (int i = 0; i < 10; i++)
        cout << i << " : " << table[i] << endl;

    return 0;
}