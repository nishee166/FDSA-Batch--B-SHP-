#include <iostream>
using namespace std;

int main() {
    int table[10], n, id;

    for (int i = 0; i < 10; i++)
        table[i] = -1;

    cout << "Enter number of vehicles: ";
    cin >> n;

    cout << "Enter vehicle registration numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> id;
        int index = id % 10;
        int count = 0;

        while (table[index] != -1 && count < 10) {
            index = (index + 1) % 10;
            count++;
        }

        if (count < 10)
            table[index] = id;
        else
            cout << "Parking lot is full\n";
    }

    cout << "Final parking slots:\n";
    for (int i = 0; i < 10; i++)
        cout << i << " : " << table[i] << endl;

    return 0;
}