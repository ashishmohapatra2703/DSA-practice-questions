/* Given an unsorted array of integers,  having **both positive and negative integers**
find the number of continuous subarrays having sum exactly equal to a given number k.

Input:
N = 5
Arr = {10 , 2, -2, -20, 10}
k = -10
Output: 3
Explanation: 
Subarrays: arr[0...3], arr[1...4], arr[3..4] have sum exactly equal to -10.

Input:
N = 6
Arr = {9, 4, 20, 3, 10, 5}
k = 33
Output: 2
Explanation: 
Subarrays : arr[0...2], arr[2...4] have sum exactly equal to 33. */

class Solution{
    public:
    int findSubArraySum(int Arr[], int N, int k)
    {
        int countSubArrSumK = 0;
        
        unordered_map<int, int> prefixSumCount; //storing the no. of subarrays with sum = prefixSum
        int prefixSum = 0;
        
        for(int i=0; i<N; i++)
        {
            prefixSum += Arr[i];

            if(prefixSum == k)
                countSubArrSumK ++;
            if(prefixSumCount.find(prefixSum-k) != prefixSumCount.end())
                countSubArrSumK += prefixSumCount[prefixSum-k];
                
            prefixSumCount[prefixSum]++;
        }
        return countSubArrSumK;
    }
};
// Time Complexity: O(N)
// Auxiliary Space: O(N)



//Similar Question --
/*Given an array of positive and negative numbers. 
Find if there is a subarray (of size at-least one) with 0 sum.

Input: [4 2 -3 1 6]
Output: Yes
Explanation: 2, -3, 1 is the subarray with sum 0.
Input: [4 2 0 1 6]
Output: Yes
Explanation: 0 is one of the element in the array so there exist a subarray with sum 0.  */

class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        int countSubArrSumK = 0;
        int k = 0;
        
        unordered_map<int, int> prefixSumCount; 
        int prefixSum = 0;
        
        for(int i=0; i<n; i++)
        {
            prefixSum += arr[i];

            if(prefixSum == k)
            {
                if(i>=1)
                    return true;
            }
            if(prefixSumCount.find(prefixSum-k) != prefixSumCount.end())
                return true;
                
            prefixSumCount[prefixSum]++;
        }
        return false;
    }
};