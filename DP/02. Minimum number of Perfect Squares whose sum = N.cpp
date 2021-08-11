/*Given a number N. 
Find the minimum number of perfect squares whose sum equals to given number n.
For Example: If N = 100 = (10*10) = (5*5 + 5*5 + 5*5 + 5*5) 
but the output will be 1 as minimum number of square is 1 , i.e 10²

Input: n = 12
Output: 3
Explanation: 12 = 2² + 2² + 2² = 4 + 4 + 4

Input: N = 6
Output: 3
Explanation 6 = 1*1 + 1*1 + 2*2 		*/

class Solution{
	public:
	int MinSquares(int n)
	{
	    int dp[n+1];
	    for(int i=1; i<=n; i++)
	        dp[i] = INT_MAX;
	    dp[0] = 0;
	    
	    for(int i=1; i<=n; i++)
	    {
	        for(int sq=1; sq*sq<=i; sq++) //possible perfect squares contribution in num = i
	        {
	            dp[i] = min( dp[i], 1+dp[i-sq*sq] );
	        }
	    }
	    //dp[i] = min number of perfect squares that sums to i 
	    return dp[n];
	}
};