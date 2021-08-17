/*The task is to count all the possible paths from top left to bottom right of a m X n matrix 
with the constraints that from each cell you can either move only to right or down.
i.e., we can move to matrix[i+1][j] or matrix[i][j+1] from matrix[i][j].

Input: m = 2, n = 2
Output: 2 
Explanation: Two possible ways are RD and DR.  

Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are RRDD, DDRR, RDDR, DRRD, RDRD, DRDR. */

//M-1
//T.C = O(m.n) and S.C = O(m.n)
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

//M-2
//T.C : O(m + n - 1))  and  S.C: O(1)
/*Use the concept of combinatorics and think.

Lets Suppose m = 5 and n = 3, we start from (0, 0) (i.e. start) and go to the end i.e. (4, 2) 
we can consider any one path lets say we choose
(0, 0) -> (0, 1) -> (0, 2) -> (1, 2) -> (2, 2) -> (3, 2) -> (4, 2)
Therefore, we moved 2 steps to the right and 4 steps downwards. 
Even if we take any other path same number of right and down steps will be required.

Now recall the combination in maths. It is just that where instead of letters we have paths. 
Here we have to cover n-1 + m-1 cellular length to destination. 

The count can be calculated using the formula (m-1 + n-1)!/(m-1)!(n-1)!. 
We have to calculate m+n-2(C)n-1 , here which will be (m+n-2)! / (n-1)! (m-1)!   */

long long  numberOfPaths(int m, int n)
{
    long path = 1; 
    for (int i = n; i < (m + n - 1); i++) 
    { 
        path *= i; 
        path /= (i - n + 1); 
    } 
    return path; 
}