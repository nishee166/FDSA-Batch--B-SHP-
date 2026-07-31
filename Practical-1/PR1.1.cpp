
#include<iostream>
using namespace std;

int main()
{
    int n, h, num;

    cout << "Enter the number of items: ";
    cin >> n;

    int arr[n];

    cout << "Enter hours: ";
    cin >> h;

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    num = h % n;

    for (int k = 0; k < num; k++)
    {
        int first = arr[0];

        for (int i = 0; i < n - 1; i++)
        {
            arr[i] = arr[i + 1];
        }

        arr[n - 1] = first;
    }

    cout << "Final array: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
