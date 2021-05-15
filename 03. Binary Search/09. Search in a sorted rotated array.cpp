//Given a sorted & rotated A[] of N DISTINCT elements which is rotated at some point, 
//and given an element K. The task is to find the index of the given element K in the array A.
#include <iostream>
using namespace std;

int iMinElementInSortedRotated(int arr[], int low, int high, int n) 
{
    while(low <= high)
    {
        if(arr[low]<=arr[high]) //if the search space is already sorted
        {
            return low;  //found minimum element at index [low]
        }
        int mid = low + (high-low)/2;
        int nexttomid = (mid+1)%n;
        int prevtomid = (mid+n-1)%n;
        
        if(arr[mid]<=arr[prevtomid] && arr[mid]<=arr[nexttomid]) //property of the minimum element of the array
        {
            return mid;
        }
        
        
        else if(arr[mid] <= arr[high]) //when right part is sorted arr[mid to high]
            high = mid-1;//search in unsorted left part
        else if(arr[low] <= arr[mid]) //when left part is sorted arr[low to mid]
            low = mid+1;//search in unsorted right part
    }
    return 0;
}

int BinarySearch(int arr[], int low, int high, int key) 
{
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(key == arr[mid])
            return mid;
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
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        int key;
        cin>>key;
        
        
        int iMin = iMinElementInSortedRotated(arr, 0, n-1, n);//index of min element in the sorted rotated array
        //In sorted rotated array the array from 0 to iMin-1
        // and the array from iMin to end is sorted 
        //Hence B.S can be appiled in both the segment to find the index of the key given
        int index1ofkey = BinarySearch(arr, 0, iMin-1, key);
        int index2ofkey = BinarySearch(arr, iMin, n-1, key);
        
        if(index1ofkey==-1 && index2ofkey==-1)
            cout<< -1 <<endl;    
        else if(index1ofkey >= 0)
            cout<< index1ofkey <<endl;
        else if(index2ofkey >= iMin)
            cout<< index2ofkey<<endl;
    }
}