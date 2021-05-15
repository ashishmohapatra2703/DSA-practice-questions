//Given an array of integers and a target sum, determine the sum nearest to but not exceeding the target that can be created.
// To create the sum, use any element of your array zero or more times. (multiple occurrence of same value)

//For example, if arr=[2,3,4] and your target sum is 10
// you might select [2,2,2,2,2], [2,2,3,3], [3,3,3,1] In this case, you can arrive at exactly the target.

//Ques) Print the maximum sum for each test case which is as near as possible, but not exceeding, to the target sum on a separate line.
#include <iostream>
using namespace std;

int UbknapSack(int wt[],int W,int n) //T.C = O(n*W)
{
    int dp[n+1][W+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<W+1; j++)
        {
            if(i==0 || j==0) //Base Condition initialization
                dp[i][j] = 0;

            else if(wt[i-1] <= j)
                dp[i][j] = max( wt[i-1]+dp[i][j-wt[i-1]] , dp[i-1][j] );
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

        int W; //capacity of knapsack ~ maxTargetSum
        cin>>W;

        int wt[n];
        for (int i=0; i<n; i++) cin>>wt[i]; //item array with their weight 

        int TargetSum = UbknapSack(wt,W,n);  //Returns the maximum sum which is as near as possible, but not exceeding, to the target sum
        cout<< TargetSum <<endl;
    }
}
// Can be multiple occurrence of the same item
// total weight of selected items need not be equal to Knapsack capacity
