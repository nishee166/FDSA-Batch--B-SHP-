#include<iostream>
using namespace std;



void bubblesort(int arr[] , int n)
{
    for(int i =0 ; i<n ; i++)
    {
        
        for(int j=0 ; j<n-i-1 ; j++)
        {
            if(arr[j] < arr[j+1])
            {
                swap(arr[j] , arr[j+1]);
               
            }
        }
       
    }
  
}


void selectionsort(int arr[] , int n)
{
    for(int i=0 ;i<n ; i++)
    {
        int si = i;
        for(int j=i+1 ; j<n ; j++)
        {
            if(arr[j]>arr[si])
            {
                si = j;            
            }
        swap(arr[i],arr[si]);
    }
}
}
void insertionsort(int arr[] , int n)
{
     for(int i= 1 ; i<n ; i++)
     {
        int curr = arr[i];
        int pre = i-1;
        while( pre>=0 && arr[pre ]< curr)
        {
            arr[pre+1] = arr[pre];
            pre--;
        }
        arr[pre+1] = curr;
     }

}



void printarray(int arr[],int n)
{
    for(int i=0 ; i<n ; i++)
    {
        cout<<arr[i]<<" ";
    }
}




int main()
{
    int n;
    cout<<"enter n:";
    cin>>n;
    int arr[n];
    cout<<"enter the elements";
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    cout<<"======================BUBBLE SORT==============================="<<endl;
    bubblesort(arr,n);
     printarray(arr,n);
     cout<<endl;

     cout<<"======================SELECTION SORT=========================="<<endl;
     selectionsort(arr,n);
     printarray(arr,n);
     cout<<endl;

     cout<<"======================SELECTION SORT=========================="<<endl;
     insertionsort(arr,n);
     printarray(arr,n);
     cout<<endl;
    
}
