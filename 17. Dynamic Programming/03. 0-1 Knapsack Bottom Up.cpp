#include <iostream>
using namespace std;
//There are 2 cases for every item : either it is included in the bag or excluded.

// Therefore, the maximum value that can be obtained from n items is max of following two values.
//1) Maximum value obtained by n-1 items and W weight (excluding nth item).
//2) Value of nth item plus maximum value obtained by n-1 items and W minus weight of the nth item (including nth item).

//Iterate the DP array for all of W and N, store the value at DP[n][W] as max of above 2 conditions.
//return DP[n][W].

int knapSack(int wt[],int val[],int W,int n) //T.C = O(n*W)
{
    int dp[n+1][W+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<W+1; j++)
        {
            if(i==0 || j==0) //Base Condition initialization
                dp[i][j] = 0;

            else if(wt[i-1] <= j)
                dp[i][j] = max( val[i-1]+dp[i-1][j-wt[i-1]] , dp[i-1][j] );
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int wt[] = { 10, 20, 30 };
    int val[] = { 60, 100, 120 };

    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);

    cout << knapSack(wt,val,W,n);  //Returns the value of maximum profit //220
    return 0;
}

