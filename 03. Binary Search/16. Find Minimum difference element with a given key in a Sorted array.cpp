#include <iostream>
#include <cstdlib>
using namespace std;

int BinarySearch(int arr[], int n, int key) 
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(key == arr[mid])
            return arr[mid]; //key present in arr //itself is the MinDiffElefromKey i.e,of diff = 0
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    //If key is not present in the arr, then 
    //After B.S , high points to index before key's hypothetical sorted position
    //and low points to index after key's hypothetical sorted position
    if( (high==n-1 && low==n) || (abs(key-arr[high]) < abs(arr[low]-key)) )
        return arr[high];
    else if( (high==-1 && low==0) || (abs(key-arr[high]) >= abs(arr[low]-key)) )
        return arr[low]; //If the difference is same for two values print the value which is greater than the Key.
}

int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int key;
        cin>>key;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>> arr[i];
        
        int MinDiffElefromKey = BinarySearch(arr, n, key); //Min Absolute Diff Element from Key
        cout<< MinDiffElefromKey <<endl;
    }
}
//OR Find the Closest Number of the Key