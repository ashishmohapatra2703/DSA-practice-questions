/*Given an array of 0s and 1s. 
Find the length of the largest subarray with equal number of 0s and 1s.

Input: N = 4  A[] = {0,1,0,1}
Output: 4
Explanation: The array from index [0...3] contains equal number of 0's and 1's.
Thus maximum length of subarray having equal number of 0's and 1's is 4. 

Time Complexity: O(N).
Auxiliary Space: O(N).  */

// return the maximum length of the subarray with equal 0s and 1s
class Solution{
public:
    int maxLen(int arr[], int N)
    {
        //taking -1 in place 0 =>
        //the problem reduces to length of largest sub-array With Sum = 0
        unordered_map<int, int> pSumIdxHash;
        int prefixSum = 0;
        int window_size = 0;
        
        for(int i=0; i<N; i++)
        {
            prefixSum += (arr[i]==0) ? -1 : 1;
            
            if(prefixSum == 0)
                window_size = max(window_size , i-0+1); //[0....i]
            if(pSumIdxHash.find(prefixSum) != pSumIdxHash.end()) //if (prefixSum-K) present in hashmap
                window_size = max(window_size , i-(pSumIdxHash[prefixSum]+1)+1); //arr[pSumIdxHash[prefixSum-K]+1 ..... i]
            
            if(pSumIdxHash.find(prefixSum) == pSumIdxHash.end()) //updation only for prefixSum first occurrence 
                pSumIdxHash[prefixSum] = i;
        }
        return window_size;
    }
};