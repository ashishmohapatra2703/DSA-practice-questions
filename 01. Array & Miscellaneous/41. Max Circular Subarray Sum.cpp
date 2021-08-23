/* Given an array arr[] of N integers arranged in a circular fashion. 
Your task is to find the maximum contiguous subarray sum.

Input: N = 7   arr[] = {8,-8,9,-9,10,-11,12}
Output: 22
Explanation:
Starting from the last element of the array, i.e, 12, and moving in a circular fashion, 
we have max subarray as 12, 8, -8, 9, -9, 10, which gives maximum sum as 22.

Input: N = 8   arr[] = {10,-3,-4,7,6,5,-4,-1}
Output: 23
Explanation: Sum of the circular subarray [7,6,5,-4,-1,10] with maximum sum is 23   */

//T.c = O(N)
class Solution{
public:
    int MaxSubArraySum(int arr[], int &n)  //(no wrapping around subarray)
    {
        int max_end_here = 0;
        int max_so_far = INT_MIN; //overall Global Max SubArray Sum
        
        for(int i=0; i<n; i++)
        {
            max_end_here += arr[i];
            max_end_here = max(max_end_here, arr[i]);    
            max_so_far = max(max_so_far, max_end_here);
        }
        
        return max_so_far;
    }
    int MinSubArraySum(int arr[], int &n)  //(no wrapping around subarray)
    {
        int min_end_here = 0;
        int min_so_far = INT_MAX; //overall Global Min SubArray Sum
        
        for(int i=0; i<n; i++)
        {
            min_end_here += arr[i];
            min_end_here = min(min_end_here, arr[i]);
            min_so_far = min(min_so_far, min_end_here);
        }
        
        return min_so_far;
    }
    
    // arr: input array
    // num: size of array
    //Function to find maximum circular subarray sum.
    int circularSubarraySum(int arr[], int num)
    {
        int sumofArr = 0;
        for(int i=0; i<num; i++)
        {
            sumofArr += arr[i];
        }
            
        int maxCircularSubArraySumOption1 = MaxSubArraySum(arr, num);
        int maxCircularSubArraySumOption2 = sumofArr - MinSubArraySum(arr, num);
        
        // arr: [-1, -2, -3]
        // MaxSubArraySum = -1 = maxCircularSubArraySumOption1 <- opt this
        // MinSubArraySum = -6
        // maxCircularSubArraySumOption2 = -6 - (-6) = 0 <- algo fails
        if(maxCircularSubArraySumOption2 == 0)  //boundary condition when all elements are -ve
            return maxCircularSubArraySumOption1;
        else
            return max(maxCircularSubArraySumOption1, maxCircularSubArraySumOption2);
    }
};