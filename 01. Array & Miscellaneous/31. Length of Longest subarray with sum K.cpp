/*Given an array having **both positive and negative integers**
 Your task is to find the length of the longest Sub-Array with 
 the sum of the elements equal to the given value K.

Input:
N = 8,  K = 0
A[] = {15,-2,2,-8,1,7,10,23}
Output: 5
Explanation: The largest subarray with sum 0 will be [-2 2 -8 1 7] => length = 5 .

Time Complexity: O(N).
Auxiliary Space: O(N). 	*/

class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        unordered_map<int, int> pSumIdxHash;
        int prefixSum = 0;
        int window_size = 0;
        
        for(int i=0; i<N; i++)
        {
            prefixSum += A[i];
            
            if(prefixSum == K)
                window_size = max(window_size , i-0+1); //[0....i]
            if(pSumIdxHash.find(prefixSum-K) != pSumIdxHash.end()) //if (prefixSum-K) present in hashmap
                window_size = max(window_size , i-(pSumIdxHash[prefixSum-K]+1)+1); //arr[pSumIdxHash[prefixSum-K]+1 ..... i]
            
            if(pSumIdxHash.find(prefixSum) == pSumIdxHash.end()) //updation only for prefixSum first occurrence 
                pSumIdxHash[prefixSum] = i;
        }
        return window_size;
    } 
};