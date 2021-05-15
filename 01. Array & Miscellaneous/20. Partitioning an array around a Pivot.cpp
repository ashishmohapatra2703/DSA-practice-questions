//re-arrange the given array in such a way that 
//all elements smaller or equal to pivot lie on the left side of pivot and 
//all elements greater than pivot lie on its right side.

#include <iostream>
using namespace std;

void ParitionAroundPivot(int arr[], int n, int pivot)
{
    //here start = 0 and end = n-1
    
    // start to j-1 : region of <= pivot
    // j to i-1     : region of > pivot
    // i to end     : region of unknown (which goes on decreasing in traversal)
    
    int i= 0 , j = 0;
    
    while(i <= n-1)
    {
        if(arr[i] > pivot)
        {
            i++;   
        }
        else if(arr[i] <= pivot)
        {
            swap(arr[i] , arr[j]);
            i++;
            j++;
        }
    }
    cout<<"partitioning index "<<j-1<<endl;
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
        int K;
        cin>>K;
            
        ParitionAroundPivot(arr, n, K);
        for(int i=0; i<n; i++) 
            cout<<arr[i]<<" ";
        cout<<endl;
    }
}