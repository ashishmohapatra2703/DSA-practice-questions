#include <iostream>
using namespace std;

int BinarySearchinSortedArray(int arr[], int n, int key) 
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

int BinarySearchinReverseSortedArray(int arr[], int n, int key) 
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; //to prevent int overflow in eqn. mid = (low+high)/2;
        if(key == arr[mid])
            return 1; //mid is the index of key found
        else if(key < arr[mid])
            low = mid+1; /////// ->
        else if(key > arr[mid])
            high = mid-1; ////// <-
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
            cin>>arr[i]; 

        if(n==1)
        {
            int isKeyPresent = BinarySearchinSortedArray(arr, n, k);
            cout<< isKeyPresent <<endl;
        }
        else // 2 or more element present in the array
        {
            if(arr[0] < arr[n-1])
            {
                int isKeyPresent = BinarySearchinSortedArray(arr, n, k);
                cout<< isKeyPresent <<endl;
            }
            else if(arr[0] > arr[n-1])
            {
                int isKeyPresent = BinarySearchinReverseSortedArray(arr, n, k);
                cout<< isKeyPresent <<endl;
            }
            else //all elements have equal value
            {
                if(arr[0] == k)
                    cout<<1<<endl;
                else
                    cout<<-1<<endl;
            }
        }
    }
    return 0;
}