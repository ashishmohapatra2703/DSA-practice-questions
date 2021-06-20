//A frog jumps either 1, 2 or 3 steps to go to top.
//In how many ways can it reach the top.

//Similar to Coin Change Problem (Max no. of ways)
//with difference that diff. Permutation of each Subsets does matter.

//// TLE
#include <iostream>
#include <cstring>
using namespace std;

int CountUnBoundedSubsetSum_WithPemutatedSubsets(int steps[], int n, int N)
{
    int dp[n+1][N+1];
    memset(dp, 0, sizeof(dp));
    
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if(i==0) 
                dp[i][j] = 0; // no step values in step[] to reach any Top stair
            if(j==0)
                dp[i][j] = 1; // dp[i][0] -> phi -> 1 way
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            for(int m=0; m<=n-1; m++) // for iteration through steps[] array values ~ 1,2,3
            {
                if(j-steps[m] >= 0) //validation of index
                    dp[i][j] += dp[i][j-steps[m]]; //equation according the staircase climbing diagram in copy
            }
        }
    }
    return dp[n][N]; // here dp[3][N];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n=3; //size of steps[] array
        int steps[3]; //steps[] array with (sorted) only 1, 2, 3 allowed steps
        steps[0] = 1;
        steps[1] = 2;
        steps[2] = 3;

        int N;
        cin>>N; //Top ~ Total No. of Steps

        int NoOfWays = CountUnBoundedSubsetSum_WithPemutatedSubsets(steps, n, N); 
        cout<< NoOfWays <<endl; //With Different Arrangement/Order of each Subset
    }
}
/*
Input: N = 4
Output: 7
Explantion:
Below are the four ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step 
 1 step + 1 step + 2 step
 2 step + 2 step
 3 step + 1 step
 1 step + 3 step
 */

//Q-2 (Passed in gfg with above code) Given a floor of dimensions 2xW and tiles of dimensions 2x1,  
//the task is to find the number of ways the floor can be tiled. 
//A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.