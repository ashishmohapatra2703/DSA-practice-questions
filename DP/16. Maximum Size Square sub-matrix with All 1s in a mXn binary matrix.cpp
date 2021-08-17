/*Given an m x n binary matrix filled with 0's and 1's, 
find the largest square containing only 1's and return its area.

Input:matrix =[ ["1","0","1","0","0"],
				["1","0","1","1","1"],
		  	  	["1","1","1","1","1"],
		  	    ["1","0","0","1","0"] ]
		Output: 2*2 = 4 					*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) 
    {
        int m = matrix.size();
        int n = matrix[0].size();
        int dp[m][n]; 
        //dp[i][j] = denotes max. size of square with all 1's , 
        //that can be made with (i,j) as the bottomright index of the square submatrix
        int max1sSqSize = 0;
        
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(matrix[i][j]-'0' == 0) //no square is possible (i,j) being at the bottom-right 
                    dp[i][j] = 0;
                
                else if(i==0)
                    dp[i][j] = matrix[0][j]-'0'; //if(matrix[0][j]==1) => dp[i][j] = 1; only size=1 sqaure is possible
                else if(j==0)
                    dp[i][j] = matrix[i][0]-'0';
                else
                {
                    dp[i][j] = 1 + min({dp[i-1][j], dp[i-1][j-1], dp[i][j-1]});
                }
                
                max1sSqSize = max(max1sSqSize, dp[i][j]);
            }
        }
        return max1sSqSize*max1sSqSize; //max. area
    }
};