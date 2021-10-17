/*You are given an array A of N **positive and/or negative integers** and a value K. 
The task is to find the count of all sub-arrays whose sum is divisible by K.

Input: N = 6, K = 5  arr[] = {4, 5, 0, -2, -3, 1}
Output: 7
Explanation: There are 7 sub-arrays whose is divisible by K 
{4, 5, 0, -2, -3, 1}, 
{5}, 
{5, 0}, 
{5, 0, -2, -3}, 
{0}, 
{0, -2, -3} and
{-2, -3}        */

class Solution{
	public:
	long long subCount(long long arr[], int N, long long K)
	{
	    long long countSubArrModK0 = 0;
	    unordered_map<long long, int> pSumModKCount;
	    int pSum = 0;
        int pSumModK;
        
        for(int i=0; i<N; i++)
        {
            pSum += arr[i];
            pSumModK = (pSum%K<0) ? pSum%K+K : pSum%K;

            if(pSumModK == 0)
                countSubArrModK0 ++;
            if(pSumModKCount.find(pSumModK) != pSumModKCount.end())
                countSubArrModK0 += pSumModKCount[pSumModK];
                
            pSumModKCount[pSumModK]++;
        }
        return countSubArrModK0;
	}
};