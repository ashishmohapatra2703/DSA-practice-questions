/*You are given weights and values of N items, put these items in a knapsack of capacity W 
to get the maximum total value in the knapsack. Note that we have only one quantity of each item.
In other words, given two integer arrays val[0..N-1] and wt[0..N-1] 
which represent values and weights associated with N items respectively. 
Also given an integer W which represents knapsack capacity, 

find out the maximum value subset of val[] such that 
sum of the weights of this subset is smaller than or equal to W. 
You cannot break an item, either pick the complete item or don’t pick it (0-1 property).

Input:
N = 3
W = 4
values[] = {1,2,3}
weight[] = {4,5,1}
Output: 3   */

//Top-Down
class Solution{
public:
    int knapSack01(int n, int W, int wt[], int val[], vector<vector<int>> &dp)
    {
        if(n==0 || W==0) //Base Condition //smallest valid i/p
            return 0;
            
        if(dp[n][W] != -1)
            return dp[n][W];
            
        if(W-wt[n-1] >= 0) //start from end element
        {
            return dp[n][W] = max( val[n-1] + knapSack01(n-1, W-wt[n-1], wt, val, dp) ,
                                    knapSack01(n-1, W, wt, val, dp) ); //Return the maximum of two cases: (1) nth item included (2) not included
        }
        else if(W-wt[n-1] < 0) //this item cannot be included in the optimal solution  since, wt[n-1] > W knapsack capacity
        {
            return dp[n][W] = knapSack01(n-1, W, wt, val, dp); // Store the value of function call stack in table dp[n][W] before return
        }
    }
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        vector<vector<int>> dp( n+1 , vector<int>(W+1, -1) );
        return knapSack01(n, W, wt, val, dp);  //Returns the maximum value subset
    }
};

//Bottom-Up
class Solution{
public:
    //Function to return max value that can be put in knapsack of capacity W.
    int knapSack(int W, int wt[], int val[], int n) 
    { 
        int dp[n+1][W+1]; // Build table dp[n+1][W+1] in bottom up manner
        
        for(int i=0; i<=n; i++)
        {
            for(int j=0; j<=W; j++)
            {
                if(i==0 or j==0)
                    dp[i][j] = 0; //Base Condition initialization
                    
                    
                else if(j-wt[i-1] >= 0) //index validation
                {
                    dp[i][j] = max( val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j]);
                }
                else if(j-wt[i-1] < 0)
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[n][W];
    }
};