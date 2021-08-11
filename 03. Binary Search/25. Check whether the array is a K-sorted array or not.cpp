/* Given an array of n distinct elements. Check whether the given array is a k sorted array or not. 
A k-sorted array is an array where each element is at most k distance away from its
target position in the sorted array.

Input:    N=6     arr[] = {3, 2, 1, 5, 6, 4} 
K = 2
Output: Yes
Explanation: sortedArr[] = {1, 2, 3, 4, 5, 6}
Every element is at most 2 distance away from its target position in the sorted array. */

//T.C = O(N.logN)
class Solution {
public:
    int binarySearch(int sortedArr[], int &n, int &key)
    {
        int low = 0;
        int high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high-low)/2;
            
            if(key == sortedArr[mid])
                return mid;
            else if(key < sortedArr[mid])
                high = mid-1;
            else if(key > sortedArr[mid])
                low = mid+1;
        }
        return -1;
    }

    string isKSortedArray(int arr[], int n, int k)
    {
        int sortedArr[n];
        for(int i=0; i<n; i++)
            sortedArr[i] = arr[i];
        sort(sortedArr, sortedArr+n);
        
        for(int i=0; i<n; i++)
        {
            int sortedIdx = binarySearch(sortedArr, n, arr[i]);
            
            if(abs(i-sortedIdx) > k)
                return "No";
        }
        
        return "Yes";
    }
};