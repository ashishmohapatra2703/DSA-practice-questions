/*Given a NxN matrix of positive integers. 
There are only three possible moves from a cell Matrix[r][c].
Matrix [r+1] [c]
Matrix [r+1] [c-1]
Matrix [r+1] [c+1]
Starting from any column in row 0 return the largest sum of any of the paths up to row N-1.

Input: N = 2
Matrix = {{348, 391},
          {618, 193}}
Output: 1009
Explaination: The best path is 391 -> 618. It gives the sum = 1009.*/

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        vector<vector<int>> dp (N, vector<int>(N,0));   
        
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                if(i==0 and j==0)
                    dp[i][j] = Matrix[i][j]; //i.e, Matrix[0][0]
                else if(i==0)
                    dp[i][j] = Matrix[i][j]; //path can start from any column in row 0
                    
                else if(j==0)
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j] , dp[i-1][j+1]); //for column 0, row 1 onwards..
                else if(j==N-1)
                    dp[i][j] = Matrix[i][j] + max(dp[i-1][j-1] , dp[i-1][j]); //for righmost N-1th column, row 1 onwards..
                else
                    dp[i][j] = Matrix[i][j] + max({dp[i-1][j-1] , dp[i-1][j], dp[i-1][j+1]}); //for rest of the cell,i.e, i>=1 and 1<=j<=N-2
            }
        }
        
        //at bottom N-1th row
        int maxSumPath = INT_MIN;
        for(int j=0; j<N; j++)
        {
            maxSumPath = max(maxSumPath, dp[N-1][j]);
        }
        return maxSumPath;
    }
};