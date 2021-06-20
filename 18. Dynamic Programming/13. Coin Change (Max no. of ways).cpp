//Given a value N, find the number of ways to make change for N cents,
//if we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins. The order of coins doesn’t matter.
//For example, for N = 4 and S = {1,2,3}, there are four solutions: {1,1,1,1},{1,1,2},{2,2},{1,3}. So output should be 4.
//For N = 10 and S = {2, 5, 3, 6}, there are five solutions: {2,2,2,2,2}, {2,2,3,3}, {2,2,6}, {2,3,5} and {5,5}. So the output should be 5.
#include <iostream>
using namespace std;

int CountUnBoundedSubsetSum(int coin[], int N, int n)
{
    int dp[n+1][N+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if(i==0) //Base Condition initialization
                dp[i][j] = 0;
            if(j==0)
                dp[i][j] = 1;
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            if(coin[i-1] <= j)
                dp[i][j] =  dp[i][j-coin[i-1]] + dp[i-1][j] ;
            else if(coin[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][N];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; //size of coin[] array
        cin>>n;

        int coin[n];
        for (int i=0; i<n; i++)
        {
            cin>>coin[i];
        }

        int N;
        cin>>N; //capacity of unbounded knapsack ~ Total Target Cents

        int result = CountUnBoundedSubsetSum(coin, N, n);
        cout<< result <<endl;
    }
}
