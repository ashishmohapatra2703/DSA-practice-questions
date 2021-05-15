//Given a sorted array A of size N. The array is rotated 'K' times. 
//Find the value of 'K'.  (R to L rotation) (Anti-Clockwise)
//The array may contain duplicate elements.

#include <iostream>
using namespace std;

int FindRotationCount(long long arr[], int low, int high) 
{
    if (low == high)
        return low;

    int mid = low + (high-low)/2;

    if(arr[mid] > arr[high])
        return FindRotationCount(arr, mid+1, high);
    else if(arr[mid] < arr[high])
        return FindRotationCount(arr, low, mid);
        
    return FindRotationCount(arr, low, high-1); //if(arr[mid] == arr[high])
} 
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        long long arr[n];
        for (long long i=0; i<n; i++) 
            cin>>arr[i]; 
        
        int ans = FindRotationCount(arr, 0, n-1);
        cout<< ans <<endl;
    }
}

//In case of Right Rotation, No. of times sorted arr is rotated == (Index of Min element)
//In case of Left Rotation, No. of times sorted arr is rotated == (length of Array - Index of Min element)