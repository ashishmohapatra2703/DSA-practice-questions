//Given an array which is sorted, but after sorting some elements are moved to either of the adjacent positions,
//i.e., arr[i] may be present at arr[i+1] or arr[i-1]. Write an efficient function to search an element in this array.
// Basically the element arr[i] can only be swapped with either arr[i+1] or arr[i-1].
#include <iostream>
using namespace std;

int BinarySearchInNearlySorted(int arr[], int n, int key)
{
    int low = 0;
    int high = n-1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;
        if(arr[mid] == key)
            return mid;
        else if(arr[mid-1] == key && mid-1 >= low) //checking to prevent out of range
            return mid-1;
        else if(arr[mid+1] == key && mid+1 <= high)
            return mid+1;


        else if(key < arr[mid])
            high = mid-2;
        else if(key > arr[mid])
            low = mid+2;
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
            cin>>arr[i]; //Nearly sorted array input

        int isKeyPresent = BinarySearchInNearlySorted(arr, n, k);
        cout<< isKeyPresent <<endl;
    }
}
