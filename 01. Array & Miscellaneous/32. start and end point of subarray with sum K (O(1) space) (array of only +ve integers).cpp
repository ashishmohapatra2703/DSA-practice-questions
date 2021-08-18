/*Given an unsorted array A of size N that **contains only non-negative integers**, 
find a continuous sub-array which adds to a given number S.

Input: N = 5, S = 12 , A[] = {1,2,3,7,5}
Output: 2 4
Explanation: The sum of elements from 2nd position to 4th position is 12.

Input: N = 10, S = 15 , A[] = {1,2,3,4,5,6,7,8,9,10}
Output: 1 5
Explanation: The sum of elements from 1st position to 5th position is 15.*/


//M-1  using hashmap  TLE
/*Beyond a certain limit for the range of keys, unordered map has to map multiple values to same location
( like chaining, etc). In such a case, search in the map may not be O(1). 
In this question, the keys can be very large (order of 10^10), hence hash table will not be very handy.*/
class Solution {
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        unordered_map<int, int> pSumIdxHash;
        int prefixSum = 0;
        
        for(int i=0; i<n; i++)
        {
            prefixSum += arr[i];

            if(prefixSum == s)
                return {1 , i+1}; //arr[0.....i]
            if(pSumIdxHash.find(prefixSum-s) != pSumIdxHash.end())
                return {pSumIdxHash[prefixSum-s]+1, i+1}; //arr[pSumIdxHash[prefixSum-s]+1 ..... i]
                
            pSumIdxHash[prefixSum] = i+1; //1-based indexing in the answer
        }
        return {-1};
    }
};

//M-2 using variable sliding window
class Solution{
public:
    //Function to find a continuous sub-array which adds up to a given number.
    vector<int> subarraySum(int arr[], int n, int s)
    {
        int i = 0; //start of window 
        int j = 0; //end of window
        int sumofsubarr = 0;
        
        while(j < n)
        {
            sumofsubarr += arr[j];
                
            if(sumofsubarr < s)
            {
                j++;
            }
            else if(sumofsubarr == s)
            {
                return {i+1, j+1};
            }
            else if(sumofsubarr > s)
            {
                while(sumofsubarr > s)
                {
                    sumofsubarr -= arr[i];
                    i++;    
                }
                if(sumofsubarr == s)
                {
                    return {i+1, j+1};
                }
                j++;
            }
        }
        
        return {-1};
    }
};