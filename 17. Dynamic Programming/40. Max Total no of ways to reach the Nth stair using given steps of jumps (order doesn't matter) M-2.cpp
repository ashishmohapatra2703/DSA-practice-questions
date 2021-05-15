//There are N stairs, and a person standing at the bottom wants to reach the top.
//The person can climb either 1 stair or 2 stairs at a time. 
//Count the number of ways, the person can reach the top (order does not matter).

//Similar to Coin Chnage Problem (Max no. of ways)

//Efficient Solution--->
//it was giving TLE because for every test case it is again computing dp matrix (more unnecessary computation)
//the better way to store dp just once globally
#include <iostream>
using namespace std;

int dp[3][1000001]; //in form of dp[n+1][N+1];   //Constraints: 1 <= N <= 10^6

void CountUnBoundedSubsetSum(int steps[], int n)
{
    for (int i=0; i<n+1; i++)   //// Build table dp[n+1][N+1] in bottom up manner
    {
        for (int j=0; j<1000001; j++)
        {
            if(i==0) //Base Condition initialization
                dp[i][j] = 0; //no step values in step[] to reach any Top stair
            if(j==0)
                dp[i][j] = 1; //dp[i][0] -> phi -> 1 way
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<1000001; j++)
        {
            if(steps[i-1] <= j)
                dp[i][j] =  dp[i][j-steps[i-1]] + dp[i-1][j] ;
            else if(steps[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
}
int main()
{
    int n=2; //here, size of steps[] array
    int steps[2]; //steps[] array with (sorted) only 1, 2 allowed steps
    steps[0] = 1;
    steps[1] = 2;
    
    CountUnBoundedSubsetSum(steps, n);
    
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N; //Top ~ Total No. of Steps

        int NoOfWays = dp[2][N]; //dp[n][N];
        cout<< NoOfWays <<endl; 
    }
}   //diff order each subsets does not matter


