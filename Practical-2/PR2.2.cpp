#include<iostream>
using namespace std;

int main()
{
    int n, tr;

    cout << "Enter n: ";
    cin >> n;

    int arr[n];

    cout << "Enter the sorted array: ";
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> tr;

    int low = 0;
    int high = n - 1;
    int found = -1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == tr)
        {
            found = mid;
            break;
        }
        else if(arr[mid] < tr)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    if(found != -1)
        cout << "Target" <<tr<< " found at position " << found;
    else
        cout << "Target not found";

    return 0;
}

