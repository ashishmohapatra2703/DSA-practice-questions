/*The task is to count all the possible paths from top left to bottom right of a m X n matrix 
with the constraints that from each cell you can either move only to right or down.
i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Input: m = 2, n = 2
Output: 2 
Explanation: Two possible ways are RD and DR.  

Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are RRDD, DDRR, RDDR, DRRD, RDRD, DRDR. */

class Solution {
  public:
    int mod = 1000000007;
    long long int numberOfPaths(int m, int n) //to find total number of unique paths.
    {
        vector<vector<long long>> dp (m, vector<long long>(n,0)); //or else can use long long dp[m][n];
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0)
                    dp[i][j] = 1; //only one way RRRRR...
                else if(j==0)
                    dp[i][j] = 1; //only one way DDDDD...
                else
                {
                    dp[i][j] = (dp[i-1][j] + dp[i][j-1]) %mod;
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};