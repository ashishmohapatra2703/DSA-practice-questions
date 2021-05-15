//Given a sorted array A of size N and a number X,
//print the count of the occurrences of X in the array, if count is zero then print -1.
#include <iostream>
using namespace std;

int FirstOccurrenceofKeyBS(int arr[], int n, int key) 
{
    int low = 0;
    int high = n-1;
    int firstindex = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; 
        if(key == arr[mid])
        {
            firstindex = mid; //found a index of the key
            high = mid-1; //further search in left
        }
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return firstindex;
}
int LastOccurrenceofKeyBS(int arr[], int n, int key) 
{
    int low = 0;
    int high = n-1;
    int lastindex = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2; 
        if(key == arr[mid])
        {
            lastindex = mid; //found a index of the key
            low = mid+1; //further search in right
        }
        else if(key < arr[mid])
            high = mid-1;
        else if(key > arr[mid])
            low = mid+1;
    }
    return lastindex;
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
        
        int FirstIndex = FirstOccurrenceofKeyBS(arr, n, k);
        int LastIndex = LastOccurrenceofKeyBS(arr, n, k);
        
        if(FirstIndex == -1) //element not found
            cout<< FirstIndex <<endl;
        else                                     //No. of Occurrences OR
            cout<< (LastIndex - FirstIndex + 1) <<endl; //Count of the given element
    }
}