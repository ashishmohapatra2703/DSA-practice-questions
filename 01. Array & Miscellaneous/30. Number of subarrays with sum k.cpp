/* Given an unsorted array of integers, 
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
            prefixSumCount[prefixSum]++;
            
            if(prefixSum == k)
                countSubArrSumK ++;
            countSubArrSumK += prefixSumCount[prefixSum-k];
        }
        return countSubArrSumK;
    }
};
// Time Complexity: O(N)
// Auxiliary Space: O(N)