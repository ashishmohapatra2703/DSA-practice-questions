//Given a sorted array arr[] of size N and given a value x.
//Find the floor of x in given array. Output the index of floor of x if exists, else print -1.
//Floor of x is defined as the largest element K in arr[] such that K is smaller than or equal to x.
#include <iostream>
using namespace std;

int FindingFloorBinarySearch(int arr[], int n, int key)
{
    int low = 0; int high = n-1;
    int floor_result = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(key == arr[mid])
            return mid;
        else if(arr[mid] > key)
        {
            high = mid-1; //search in left segment
        }
        else if(arr[mid] < key) //possible candidate
        {
            floor_result = mid; //store the candidate and then
            low = mid+1; //search in right segment
        }
    }
    return floor_result;
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

        int floorofkey = FindingFloorBinarySearch(arr, n, k);
        cout<< floorofkey<<endl;
    }
}

//OR
#include <iostream>
using namespace std;

int FindingFloorBinarySearch(int arr[], int n, int key) 
{
    int low = 0; 
    int high = n-1;

    while(low <= high)
    {
        int mid = low + (high-low)/2;
        
        if(key == arr[mid])
            return mid;
        else if(arr[mid] > key)
            high = mid-1; 
        else if(arr[mid] < key) 
            low = mid+1; 
    }
    return high;//After B.S , high points to index before key's hypothetical sorted position
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
        
        int floorofkey = FindingFloorBinarySearch(arr, n, k);
        cout<< floorofkey<<endl;
    }
}