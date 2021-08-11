/*Given a number n, the task is to 
break n in such a way that multiplication of its parts is maximized. 

Input : n = 10  ,  Output : 36
10 = 4 + 3 + 3 and 4 * 3 * 3 = 36 is maximum possible product.

Input : n = 8   ,  Output : 18
8 = 2 + 3 + 3 and 2 * 3 * 3 = 18 is maximum possible product. */

class Solution {
public:
    int integerBreak(int n) 
    {
        int dp[n+1];
        for(int i=0; i<=n; i++)
	        dp[i] = INT_MIN;
        dp[1] = 1;
        
        for(int i=2; i<=n; i++)
        {
            for(int br=1; br<=i-1; br++) // breaking at 1,2,.....n-1
            {
                dp[i] = max(dp[i] , br*max(dp[i-br],i-br) );
            }
        }
        return dp[n];
    }
};

//new scenario, same algo.
/*Given a rope of length N meters, cut the rope in different parts of
integer lengths in a way that maximizes the product of lengths of all parts. 
You must make at least one cut. Assume that the length of the rope is more than one meter.
Note: Answer can be large. So, output answer modulo 10^9+7

Input: N = 5
Output: 6
Explanation: Maximum obtainable product is 2*3   */

		dp[i] = max(dp[i]%mod , br*max(dp[i-br]%mod, i-br));