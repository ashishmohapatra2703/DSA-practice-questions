// Given a rod of length N inches and an array of prices that contains prices of all pieces of size smaller than N.
// Determine the maximum value obtainable by cutting up the rod and selling the pieces.

//Same as the concept of unbounded knapsack

#include <iostream>
using namespace std;

int maxPriceInCutting(int length[],int price[],int N,int n) //T.C = O(n*N)
{
    int dp[n+1][N+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            if(i==0 || j==0) //Base Condition initialization
                dp[i][j] = 0;

            else if(length[i-1] <= j)
                dp[i][j] = max( price[i-1]+dp[i][j-length[i-1]] , dp[i-1][j] );
            else if(length[i-1] > j)
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
        int N; //initial rod length given
        cin>>N;

        int n=N; //here size of array = n = N (No constrains in piece_length)
                 //can be broken with any piece_length 1 to n
        int length[n];
        for(int i=0; i<n; i++)
        {
            length[i] = i+1; //length of pieces can be from 1 to N
        }
        int price[n];
        for(int i=0; i<n; i++)
        {
            cin>>price[i]; //price of pieces corresponding to piece_length 1 to N
        }

        int ans = maxPriceInCutting(length,price,N,n);  //Returns the value of maximum profit
        cout<< ans <<endl;
    }
}
// Can be multiple occurrence of the same item

// Added length of selected piece_lengths need not be equal to N
// Only condition is to maximixe the price