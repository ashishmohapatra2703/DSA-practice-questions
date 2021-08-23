/*Given an array containing 0s and 1s. 
Find the number of subarrays having equal number of 0s and 1s.

Input: n = 7  A[] = {1,0,0,1,0,1,1}
Output: 8
Explanation: The index range for the 8 sub-arrays are: 
			(0, 1), (2, 3), (0, 3), (3, 4), (4, 5) ,(2, 5), (0, 5), (1, 6)

Input: n = 5  A[] = {1,1,1,1,0}
Output: 1
Explanation: The index range for the subarray is (3,4).*/

class Solution{
public:
    //Function to count subarrays with 1s and 0s.
    long long int countSubarrWithEqualZeroAndOne(int arr[], int n)
    {
        //taking -1 in place 0 =>
        //the problem reduces to count no. of Sub-arrays With Sum = 0
        int countSubArrSum0 = 0;
        unordered_map<int, int> prefixSumCount; //storing the no. of subarrays with sum = prefixSum
        int prefixSum = 0;
        
        for(int i=0; i<n; i++)
        {
            prefixSum += (arr[i]==0) ? -1 : 1;

            if(prefixSum == 0)
                countSubArrSum0 ++;
            if(prefixSumCount.find(prefixSum) != prefixSumCount.end())
                countSubArrSum0 += prefixSumCount[prefixSum];
                
            prefixSumCount[prefixSum]++;
        }
        return countSubArrSum0;
    }
};