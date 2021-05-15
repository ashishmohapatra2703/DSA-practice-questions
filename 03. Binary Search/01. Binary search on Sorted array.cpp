#include <iostream>
using namespace std;

int BinarySearch(int arr[], int n, int key) 
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; //to prevent int overflow in eqn. mid = (low+high)/2;
        if(key == arr[mid])
            return 1; //mid is the index of key found
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return -1; //key not found unsuccessful search
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i]; //sorted array input
        
        int isKeyPresent = BinarySearch(arr, n, k);
        cout<< isKeyPresent <<endl;
    }
}