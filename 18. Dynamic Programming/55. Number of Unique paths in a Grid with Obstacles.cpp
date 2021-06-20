/*Given a grid of size m*n, let us assume you are starting at (0, 0) and your goal is to reach 
(m, n). At any instance, if you are on (x, y), you can either go to (x, y+1) or (x+1, y).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and empty space are marked as 1 and 0 respectively in the grid.  
Input:
[
  [0,0,0],
  [0,1,0],
  [0,0,0]
]
Output: 2
Explanation:
There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right   */

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int dp[m][n]; //each dp[i][j] denotes number of paths to (i,j) from (0,0)
        memset(dp, 0, sizeof(dp));
        

        if(obstacleGrid[0][0] == 1) //obstacle in starting cell 
            return 0; // no paths to the destination

        for(int i=0,j=0;  i<m;  i++) //BASE CONDITION FOR TOTAL 1st COLUMN
        {
            if (obstacleGrid[i][j] == 0) //empty space
                dp[i][j] = 1; //every cell in 1st column will have single path
            else if (obstacleGrid[i][j] == 1)//obstacle
                break;//every cell down the obstacle (i,0) will have no paths
        }
        for(int j=0,i=0;  j<n;  j++) //BASE CONDITION FOR TOTAL 1st ROW
        {
            if (obstacleGrid[i][j] == 0) //empty space
                    dp[i][j] = 1; //every cell in 1st column will have single path
            else if (obstacleGrid[i][j] == 1)//obstacle
                break;//every cell right to the obstacle (0,j) will have no paths
        }
        
        
        for(int i=1; i<m; i++)
        {
            for(int j=1; j<n; j++)
            {
                if (obstacleGrid[i][j] == 0) //empty space
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
                /*else if (obstacleGrid[i][j] == 1)//obstacle
                {
                    dp[i][j] = 0;
                }*/ //already every had 0 in it
            }
        }
        return dp[m-1][n-1];
    }     
};