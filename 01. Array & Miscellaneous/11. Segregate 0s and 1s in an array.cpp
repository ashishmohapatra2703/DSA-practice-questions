//Given a binary array A[] of size N. The task is to arrange array in increasing order.
//Note: The binary array contains only 0  and 1.
#include <iostream>
#include <algorithm>
using namespace std;

void Sort(int arr[], int n)
{
    int low = 0;
    int high = n-1;
    
    while(low <= high)
    {
        if(arr[low] == 1 && arr[high] == 0)
        {
            swap(arr[low] , arr[high]);
            low++;
            high--;
        }
        if(arr[low] == 0)
        {
            low++;
        }
        if(arr[high] == 1)
        {
            high--;
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++) 
            cin>>arr[i];
            
        Sort(arr, n);
        for(int i=0; i<n; i++) 
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}