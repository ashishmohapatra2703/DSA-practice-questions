#include <iostream>
using namespace std;

int UbknapSack(int wt[],int val[],int W,int n) //T.C = O(n*W)
{
    int dp[n+1][W+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<W+1; j++)
        {
            if(i==0 || j==0) //Base Condition initialization
                dp[i][j] = 0;

            else if(wt[i-1] <= j)
                dp[i][j] = max( val[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j] );
            else if(wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //no. of items
        int W; //capacity of knapsack
        cin>>W;

        int val[n];
        for (int i=0; i<n; i++) cin>>val[i];
        int wt[n];
        for (int i=0; i<n; i++) cin>>wt[i];

        int maxProfit = UbknapSack(wt,val,W,n);  //Returns the value of maximum profit
        cout<< maxProfit <<endl;
    }
}
// Can be multiple occurrence of the same item
// total weight of selected items need not be equal to Knapsack capacity
