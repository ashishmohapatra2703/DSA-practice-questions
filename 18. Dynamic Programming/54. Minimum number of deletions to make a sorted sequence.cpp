/*Given an array arr of size N, the task is to remove or delete the minimum number of elements
 from the array so that when the remaining elements are 
 placed in the same sequence order form an increasing sorted sequence.
Input: N = 5, arr[] = {5, 6, 1, 7, 4}
Output: 2
Explanation: Removing 1 and 4 leaves the remaining sequence order as 5 6 7 which is a sorted sequence
Input: N = 3, arr[] = {1, 1, 1}
Output: 2
Explanation: Remove 2 1's  */
class Solution{
public:
	int minDeletions(int arr[], int n) 
	{ 
	    int LIS[n+1];
        for(int i=0; i<n; i++)
        { 
            LIS[i] = 1;
        }
        
        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if((arr[j] < arr[i]))
                {
                    LIS[i] = max(LIS[i] , 1+LIS[j]);
                }
            }
        }
        //LIS[i] stores the lenLIS -- starting from arr[0] ending with arr[i]
        //overall lenLIS of arr = max(LIS[i])
        int lenLIS = 0;
        for(int i=0; i<n; i++)
        {
            lenLIS = max(lenLIS, LIS[i]);
        }
        return n-lenLIS; //min no. deletions = n - length of LIS
	} 
};