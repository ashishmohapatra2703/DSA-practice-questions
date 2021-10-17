/*Given a sorted array arr[] of size N and an integer K. The task is to check 
if K is present in the array or not using ternary search.

Ternary Search- It is a divide and conquer algorithm that can be used to find an element in an array. 
In this algorithm, we divide the given array into three parts and determine which has the key (searched element).

Time Complexity: O(2*Log₃N)
Auxiliary Space: O(1)      */

class Solution{
    public:
    // Function to find element in sorted array
    // arr: input array
    // N: size of array
    // K: element to be searche
    int ternarySearch(int arr[], int N, int K) 
    { 
        int low = 0;
        int high = N-1;
        while(low <= high)
        {
            int mid1 = low + (high-low)/3;
            int mid2 = high - (high-low)/3;
            
            if(K == arr[mid1] or K == arr[mid2])
                return 1;
            else if(K < arr[mid1])
                high = mid1-1;
            else if(K > arr[mid2])
                low = mid2+1;
            else// if(arr[mid1] < K and K > arr[mid2])
            {
                low = mid1+1;
                high = mid2-1;
            }
        }
        return -1; //key not found unsuccessful search
    }
};