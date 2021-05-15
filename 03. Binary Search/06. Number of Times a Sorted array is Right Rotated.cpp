//Given a sorted array A of size N. The array is rotated 'K' times. 
//Find the value of 'K'.  (R to L rotation) (Anti-Clockwise)
//The array may contain duplicate elements.
//////////////// (can't handle duplicate cases)
#include <iostream>
using namespace std;

int FindRotationCount(int arr[], int n) 
{
    int low = 0;
    int high = n-1;
    
    int IndexofMin = 0; //**** no. of times sorted arr is rotated == Index of Min element ****
    while(low <= high)  
    {   
        //Firstly, when array is not rotated at all
        if(arr[low] <= arr[high]) //further if the search space is already sorted
        {
            IndexofMin = low; //found minimum element at index [low]
            return IndexofMin;
        }  //optimization (will work if no duplicate elements present)
        
        int mid = low + (high-low)/2;
        int nexttomid = (mid+1)%n;
        int prevtomid = (mid+n-1)%n;
        
        if(arr[mid]<=arr[prevtomid] && arr[mid]<=arr[nexttomid]) //property of the minimum element of sorted rotated array
        {
            IndexofMin = mid;
            return IndexofMin;
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
    return IndexofMin; //in case all elements are same
}
//OR Recursive Method
int FindRotationCount(long long arr[], int low, int high) 
{
    if (low == high)
        return low;

    int mid = low + (high-low)/2;

    if(arr[mid] > arr[high])
        return FindRotationCount(arr, mid+1, high);
    else if(arr[mid] < arr[high])
        return FindRotationCount(arr, low, mid);
        
    return mid; //if(arr[mid] == arr[high])
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
        
        int ans = FindRotationCount(arr, n);//index of min element in the rotated array
        cout<< ans <<endl;
    }
}

//In case of R of L Rotation, No. of times sorted arr is rotated == (Index of Min element)
//In case of L to R Rotation, No. of times sorted arr is rotated == (length of Array - Index of Min element)