#include <iostream>
#include <vector>
using namespace std;

void ReverseArray(int arr[], int n) 
{
    int i = 0;
    int j = n-1;
    while(i<=j)
    {
        swap(arr[i] , arr[j]);
        i++;
        j--;
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
            
        ReverseArray(arr, n);
        
        for(int i=0; i<n; i++) 
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}