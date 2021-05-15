/*Given two natural number n and m. The task is to find the number of ways 
in which the numbers that are greater than or equal to m can be added to get the sum n.
Examples:
Input : n = 3, m = 1
Output : 3
Following are three different ways
to get sum n such that each term is
greater than or equal to m
1 + 1 + 1 , 1 + 2 , 3 

Input : n = 2, m = 1
Output : 2
ways are 1 + 1 , 2       *similar to coin change problem (max no. of ways)*    */
#include <iostream>
#include <vector>
using namespace std;

int CountUnBoundedSubsetSum(vector<int> coin, int N, int n)
{
    int dp[n+1][N+1];
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
        int N;
        cin>>N; //capacity of unbounded knapsack ~ Total Target Cents

        int m;
        cin>>m;
        vector<int> coin;
        for (int i=m; i<=N; i++)
        {
            coin.push_back(i);
        }
        int n = coin.size();

        int result = CountUnBoundedSubsetSum(coin, N, n);
        cout<< result <<endl;
    }
}
