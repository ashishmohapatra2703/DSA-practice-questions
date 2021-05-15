/*Given an array of integers which is initially increasing and then decreasing, (A[i] != A[i+1])
find the maximum value in the array i.e, the bitonic point. 
Examples :
Input: arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1}
Output: 500

Input: arr[] = {1, 3, 50, 10, 9, 7, 6}
Output: 50

Corner case (No decreasing part)
Input: arr[] = {10, 20, 30, 40, 50}
Output: 50

Corner case (No increasing part)
Input: arr[] = {120, 100, 80, 20, 0}
Output: 120  */

//M-1 Linear Search
//M-2 Binary Search (Same as finding peak element)
class Solution{
public:
	
	int findMaximum(int arr[], int n) 
	{
	    int low = 0;
        int high = n-1;
        
        while(low <= high)
        {
            int mid = low + (high - low)/2;
            if(mid>=1 && mid<=n-2)
            {
                if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1]) 
                    return arr[mid];
            }
            if(mid==0)
            {
                if(arr[mid] > arr[mid+1])
                    return arr[mid];
            }
            if(mid==n-1)
            {
                if(arr[mid] > arr[mid-1])
                    return arr[mid];
            }
            
    
            else if(arr[mid+1] > arr[mid])
                low = mid + 1;
            else if(arr[mid-1] > arr[mid])
                high = mid - 1;
            //go for that segment which have greater neighbour
            //for which arr[mid] couldn't become bitonic point
        }
        return -1;
	}
};