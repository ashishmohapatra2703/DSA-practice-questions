/*Given a floor of size n x m and tiles of size 1 x m. The problem is to 
Count the number of ways to tile the given floor using 1 x m tiles. 
A tile can either be placed horizontally or vertically.
Both n and m are positive integers and 2 < = m.

Input: n = 2, m = 3
Output: 1
Expanation: There is only one way to tile the given floor.

Input: n = 4, m = 4
Output: 2
Explanation: There is two ways to tile the given floor.
One way is to place 1 x 4 size of tile vertically and 
another one is to place them horizontally.*/

class Solution{
public:
    int mod = 1000000007;
	int countWays(int n, int m)
	{
	    if(m > n)
	        return 1;
	        
	    int dp[n+1];
	    dp[0] = 1;
	    
	    for(int i=1; i<=n; i++)
	    {
	        if(i-m >=0) //index validation
	            dp[i] = (dp[i-1] + dp[i-m]) %mod;
            else
                dp[i] = dp[i-1] %mod;
	    }
	    return dp[n];
	}
};

//or can do like this
class Solution{
public:
    int mod = 1000000007;
	int countWays(int n, int m)
	{
	    if(m > n)
	        return 1;
	        
	    int dp[n+1];
	    
	    for(int i=0; i<m; i++)
	        dp[i] = 1;
	        
	    for(int i=m; i<=n; i++)
	    {
	        dp[i] = (dp[i-1] + dp[i-m]) %mod;
	    }
	    return dp[n];
	}
};