//A sorted array A[] with DISTINCT elements is rotated at some unknown point, 
//the task is to find the minimum element in it.

//Similar to finding "Number of Times a Sorted array is Right Rotated"
              // => "Index of Min Element in Sorted Right Rotated Array"
//here, we have to just find the arr[iMin]
#include <iostream>
using namespace std;

int MinElementInSortedRotated(int arr[], int n) 
{
    int low = 0;
    int high = n-1;
    
    int iMin = 0;
    while(low <= high)
    {
        if(arr[low]<=arr[high]) //if the search space is already sorted
        {
            iMin = low; //found minimum element at index [low]
            return arr[iMin];
        } //optimization
        
        int mid = low + (high-low)/2;
        int nexttomid = (mid+1)%n;
        int prevtomid = (mid+n-1)%n;
        
        if(arr[mid]<=arr[prevtomid] && arr[mid]<=arr[nexttomid]) //property of the minimum element of the array
        {
            iMin = mid;
            return arr[iMin];
        }
        else if(arr[mid] <= arr[high]) //when right part is sorted arr[mid to high]
        {
            high = mid-1;//search in unsorted left part
        }
        else if(arr[low] <= arr[mid]) //when left part is sorted arr[low to mid]
        {
            low = mid+1;//search in unsorted right part
        }
    }
    return arr[iMin];
}

int MinElementInSortedRotated(int arr[], int low, int high) 
{
    if (low == high)
        return arr[low];

    int mid = low + (high-low)/2;

    if(arr[mid] > arr[high])
        return MinElementInSortedRotated(arr, mid+1, high);
    else if(arr[mid] < arr[high])
        return MinElementInSortedRotated(arr, low, mid);
        
    return arr[mid]; //if(arr[mid] == arr[high])
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
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        
        int ans = MinElementInSortedRotated(arr, n);
        cout<< ans <<endl;
    }
}