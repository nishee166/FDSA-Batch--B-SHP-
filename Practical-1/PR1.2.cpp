#include<iostream>
using namespace std;

int main()
{
    int n;
    int book[100];
    int printed[100];

    cout << "Enter number of borrow records: ";
    cin >> n;

    cout << "Enter Book IDs:\n";
    for(int i = 0; i < n; i++)
    {
        cin >> book[i];
        printed[i] = 0;      // 0 means not printed
    }

    cout << "\nBooks borrowed more than once are:\n";

    int found = 0;

    for(int i = 0; i < n; i++)
    {
        if(printed[i] == 1)
            continue;

        int count = 1;

        for(int j = i + 1; j < n; j++)
        {
            if(book[i] == book[j])
            {
                count++;
                printed[j] = 1;
            }
        }

        if(count > 1)
        {
            cout << book[i] << endl;
            found = 1;
        }
    }

    if(found == 0)
    {
        cout << "No duplicate book IDs found.";
    }

    return 0;
}
