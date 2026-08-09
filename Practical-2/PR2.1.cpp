
#include <iostream>
using namespace std;

int main() {
    int n; int f; int g;
    cout<<"enter the n:";
    cin>>n;
    int arr[n];
    cout<<"enter the array:";
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }

    cout<<"enter the guard left";
    cin>>g;
    cout<<"enter number like to found";
    cin>>f;
    bool found = false;
    for(int i=0 ; i<g ; i++)
    {
        if(arr[i] == f)
        {
            cout<<"number found at position"<<i;
            found = true;
            break;
            
        }
    }    
    if (!found)
        {
            for(int i=g ; i<n ;i++ )
            {
                if(arr[i] == f)
                {
                cout<<"number founf at position "<<i;
                found = true;
                break;
                }
            }
        }

    
     

    return 0;
}
