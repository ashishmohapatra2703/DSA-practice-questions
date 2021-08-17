/*A robot is located at the top-left corner of a m x n grid (0,0).
The robot can only move either down or right at any point in time. 
The robot is trying to reach the bottom-right corner of the grid (m-1, n-1).
Now consider if some obstacles are added to the grids. How many unique paths would there be?
An obstacle and space is marked as 1 and 0 respectively in the grid.

Input: 
obstacleGrid =[ [0,0,0],
				[0,1,0],
				[0,0,0] ]
Output: 2
Explanation: There is one obstacle in the middle of the 3x3 grid above.
There are two ways to reach the bottom-right corner:
1. Right -> Right -> Down -> Down
2. Down -> Down -> Right -> Right 	*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        int dp[m][n]; //each dp[i][j] denotes number of paths to (i,j) from (0,0)
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(obstacleGrid[i][j] == 1) //obstacle
                    dp[i][j] = 0;
                
                //else => if (i,j) empty cell
                else if(i==0 and j==0)
                    dp[i][j] = !obstacleGrid[i][j]; //i.e,obstacleGrid[0][0] //if obstacle in starting cell(0,0) => no path to the destination
                else if(i==0)
                    dp[i][j] = dp[i][j-1]; //every cell in 0th row will have single path, but cells down the obstacle dp[i][j]=0 will have no paths
                else if(j==0)
                    dp[i][j] = dp[i-1][j]; //every cell in 0th column will have single path, but cells right to the obstacle dp[i][j]=0 will have no paths
                else
                {
                    dp[i][j] = dp[i-1][j] + dp[i][j-1];
                }
            }
        }
        return dp[m-1][n-1]; 
    }
};


//another style of code, same logic
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

        for(int j=0,i=0;  j<n;  j++) //BASE CONDITION FOR TOTAL 0th ROW
        {
            if (obstacleGrid[i][j] == 0) //empty space
                dp[i][j] = 1; //every cell in 0th row will have single path, RRRRR....
            else if (obstacleGrid[i][j] == 1)//obstacle
                break;//every cell right to the obstacle will have no paths
        }

        for(int i=0,j=0;  i<m;  i++) //BASE CONDITION FOR TOTAL 0th COLUMN
        {
            if (obstacleGrid[i][j] == 0) //empty space
                dp[i][j] = 1; //every cell in 1st column will have single path, DDDDD....
            else if (obstacleGrid[i][j] == 1)//obstacle
                break;//every cell down the obstacle will have no paths
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