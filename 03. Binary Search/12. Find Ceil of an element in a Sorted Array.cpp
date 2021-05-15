//Given a sorted array arr[] of size N without duplicates, and given a value x.
//Find the ceil of x in given array.
//ceil of x is defined as the smallest element K in arr[] such that K is greater than or equal to x.
#include <iostream>
using namespace std;

int FindingCeilBinarySearch(int arr[], int n, int key)
{
    int low = 0; int high = n-1;
    int ceil_result = -1;
    while(low <= high)
    {
        int mid = low + (high-low)/2;

        if(key == arr[mid])
            return arr[mid];
        else if(arr[mid] > key) //possible candidate
        {
            ceil_result = mid; //store the candidate and then
            high = mid-1; //search in left segment
        }
        else if(arr[mid] < key)
        {
            low = mid+1; //search in right segment
        }
    }
    return ceil_result;
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

        int ceilofkey = FindingCeilBinarySearch(arr, n, k);
        cout<< ceilofkey<<endl;
    }
}

