/* Given N dice each with M faces, numbered from 1 to M, find the number of ways (out of M^N total ways) 
to get taregt sum X. X is the summation of values on each face when all the dice are thrown.

Input:  
M = 6 (faces= 1/2/3/4/5/6) 
N = 2 (total dices) 
X = 7 (target Sum)
Output:  6
Explanation: There are 6 total ways to get the Sum 7 using 2 dices with faces from 1 to 6. 
1+6, 2+5, 3+4, 4+3, 5+2, 6+1.   */

//Top-Down
class Solution{
public:
    int mod = 1000000007;
    long long dicesCombinationSum(int &faces, int dices, int target, vector<vector<long long>> &dp)
    {
        if(dices==0 and target==0) //all dices used and the taregt sum is achieved
            return 1;
        else if(target<=0 and dices>0) //where dices remaining are > 0 and target sum already crosses
            return 0;
        else if(dices==0) //target is not yet achieved and dices finishes
            return 0;
        
        if(dp[dices][target] != -1)
            return dp[dices][target];
        

        long long ways = 0;
        for(int k=1; k<=faces; k++)
        {
            ways += dicesCombinationSum(faces, dices-1, target-k, dp);
        }
        return dp[dices][target] = ways;
    }
    
    long long noOfWays(int M , int N , int X) 
    {
        vector<vector<long long>> dp (N+1, vector<long long>(X+1, -1));
        return dicesCombinationSum(M, N, X, dp);
    }
};

//Bottom-Up
class Solution{
  public:
    long long noOfWays(int M , int N , int X) 
    {
        long long dp[N+1][X+1];
        memset(dp, 0 ,sizeof(dp));
        
        for(int i=0; i<=N; i++)
        {
            for(int j=0; j<=X; j++)
            {
                if(i==0 and j==0)
                    dp[i][j] = 1;
                else if(i==0 or j==0)
                    dp[i][j] = 0;
                
                else
                {
                    for(int k=1; k<=M and j-k>=0; k++) //with index validation
                    {
                        dp[i][j] += dp[i-1][j-k];
                    } 
                }
            }
        }
        return dp[N][X];
    }
};