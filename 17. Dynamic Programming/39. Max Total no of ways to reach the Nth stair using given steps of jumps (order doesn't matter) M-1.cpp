//There are N stairs, and a person standing at the bottom wants to reach the top.
//The person can climb either 1 stair or 2 stairs at a time. 
//Count the number of ways, the person can reach the top (order does not matter).

//Similar to Coin Change Problem (Max no. of ways)
#include <iostream>
using namespace std;

int CountUnBoundedSubsetSum(int steps[], int n, int N)
{
    int dp[n+1][N+1]; // Build table dp[n+1][W+1] in bottom up manner
    
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if(i==0) //Base Condition initialization
                dp[i][j] = 0; //no step values in step[] to reach any Top stair
            if(j==0)
                dp[i][j] = 1; //dp[i][0] -> phi -> 1 way
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            if(steps[i-1] <= j)
                dp[i][j] =  dp[i][j-steps[i-1]] + dp[i-1][j] ;
            else if(steps[i-1] > j)
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
        int n=2; //size of steps[] array
        int steps[2]; //steps[] array with (sorted) only 1, 2 allowed steps
        steps[0] = 1;
        steps[1] = 2;

        int N;
        cin>>N; //Top ~ Total No. of Steps

        int NoOfWays = CountUnBoundedSubsetSum(steps, n, N); 
        cout<< NoOfWays <<endl; //diff order each subsets does not matter
    }
}

//Q-2 Consider a game where a player can score 3 or 5 or 10 points in a move. 
//Given a total score n, find the number of distinct combinations to reach the given score.