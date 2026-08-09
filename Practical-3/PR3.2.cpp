#include<iostream>
using namespace std;

void dutch(int arr[] , int n)
{
    int low = 0 , mid = 0 , high = n-1;
    while(mid <= high){
         if(arr[mid] == 0)
         {
            swap(arr[low] , arr[mid]);
            low++;
            mid++;
         }
         else if(arr[mid] == 1)
         {
            mid++;
        }
        else if(arr[mid] == 2)
        {
            swap(arr[mid] ,arr[high]);
            high--;
        }
               
    }
}
void printarray(int arr[] , int n)
{
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}

void counting(int arr[] , int n)
{
    int count0 = 0 , count1 = 0 , count2 = 0;
    for(int i=0 ; i<n ; i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        else if(arr[i] == 1)
        {
            count1++;
        }
        else if(arr[i] == 2)
        {
            count2++;
        }


    }
    for(int i=0 ; i<count0; i++)
    {
             arr[i] = 0;
    }
     for(int i=count0 ; i< count0+count1; i++)
    {
             arr[i] = 1;
    }
     for(int i=count1+count0 ; i< count0+count1+count2; i++)
    {
             arr[i] = 2;
    }
    
    
    

    
}

int main()
{
         int n; 
         cout<<"enter n";
         cin>>n;
        
    int arr[n];

    cout<<"enter the colur codes 0,1 or 2";
    for(int i=0 ; i<n ; i++)
    {
        cin>>arr[i];
    }
    cout<<"==================== DUTCH FLAG NATIONAL ALGORITHM ========================"<<endl;
    dutch(arr,n);
    printarray(arr,n);
    cout<<endl;
     cout<<"==================== COUNTING SORT  ========================"<<endl;

     counting(arr,n);
     printarray(arr,n);


   
    
 }
