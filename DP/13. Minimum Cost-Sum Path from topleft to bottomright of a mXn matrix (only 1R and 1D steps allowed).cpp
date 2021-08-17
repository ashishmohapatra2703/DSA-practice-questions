/*Given a m x n grid filled with non-negative numbers, find a path 
from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Input: grid = [ [1,3,1],
                [1,5,1],
                [4,2,1] ]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp (m, vector<int>(n,0));   
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i==0 and j==0)
                    dp[i][j] = grid[i][j]; //i.e, grid[0][0]
                else if(i==0)
                    dp[i][j] = grid[i][j] + dp[i][j-1];
                else if(j==0)
                    dp[i][j] = grid[i][j] + dp[i-1][j]; 
                else
                {
                    dp[i][j] = grid[i][j] + min(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};