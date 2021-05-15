//Coin Change Problem Minimum Numbers of coins
// Given a value V, if we want to make change for V cents, and we have infinite supply of each of C = { C1, C2, .. , Cm} valued coins,
// what is the minimum number of coins to make the change?

//Example:
//Input: coins[] = {25, 10, 5}, V = 30
//Output: Minimum 2 coins required
//We can use one coin of 25 cents and one of 5 cents

#include <iostream>
#include <climits>
using namespace std;

int MinMemberUnboundedSubset(int coin[], int N, int n)
{
    int dp[n+1][N+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            //you would first look at the bag of coins and then the value of the sum,
            //if you have no coins in the bag, you need not to look at the sum,
            //it would definitely be INT_MAX or INT_MAX-1 (to avoid overflow)
            if(j==0)
                dp[i][j] = 0;
            if(i==0)              //Base Condition initialization
                dp[i][j] = INT_MAX-1;

        }
    }

    for (int i=1,j=1; j<N+1; j++) //2nd row initialization
    {
        if(j%coin[0] == 0)    //here coin[i-1] ~ coin[0]
            dp[i][j] = j/coin[0];
        else
            dp[i][j] = INT_MAX-1;
    }

    for (int i=2; i<n+1; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            if(coin[i-1] <= j)
                dp[i][j] =  min( 1+dp[i][j-coin[i-1]] , dp[i-1][j] ) ; //including the coin will raise the number of coins by 1
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
        cin>>N; //Total Target Cents

        int n; //size of coin[] array
        cin>>n;
        int coin[n];
        for (int i=0; i<n; i++)
        {
            cin>>coin[i];
        }

        int result = MinMemberUnboundedSubset(coin, N, n); //minimum number of coins to make the change
        if(result == INT_MAX-1)
            cout<< "-1" <<endl; //not possible to make the change with given coins
        else
            cout<< result <<endl;
    }
}


//To find actual value of change coins in result not just the number of coins --->
//Given a value N, total sum you have. You have to make change for Rs. N, and 
//there is infinite supply of each of the denominations in Indian currency, 
//i.e., you have infinite supply of { 1, 2, 5, 10, 20, 50, 100, 200, 500, 2000} valued coins/notes, 
//Find the minimum number of coins and/or notes needed to make the change for Rs N.

#include <iostream>
#include <climits>
#include <vector>
using namespace std;

vector<int> MinMemberUnboundedSubset(int coin[], int N, int n)
{
    int dp[n+1][N+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<N+1; j++)
        {
            //you would first look at the bag of coins and then the value of the sum,
            //if you have no coins in the bag, you need not to look at the sum,
            //it would definitely be INT_MAX or INT_MAX-1 (to avoid overflow)
            if(j==0)
                dp[i][j] = 0;
            if(i==0)              //Base Condition initialization
                dp[i][j] = INT_MAX-1;

        }
    }

    for (int i=1,j=1; j<N+1; j++) //2nd row initialization
    {
        if(j%coin[0] == 0)    //here coin[i-1] ~ coin[0]
            dp[i][j] = j/coin[0];
        else
            dp[i][j] = INT_MAX-1;
    }

    for (int i=2; i<n+1; i++)
    {
        for (int j=1; j<N+1; j++)
        {
            if(coin[i-1] <= j)
                dp[i][j] =  min( 1+dp[i][j-coin[i-1]] , dp[i-1][j] ) ; //including the coin will raise the number of coins by 1
            else if(coin[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    int MinNumofCoin = dp[n][N];
    
    //trace back from dp[n][N] to find actual value of coins
    vector<int> ans;
    int row = n;
    int column = N;
    while(row>0 && column>0)
    {
        if(dp[row][column] == dp[row-1][column])
        {
            row--;
        }
        else if(dp[row][column] == 1 + dp[row][column-coin[row-1]])
        {
            ans.push_back(coin[row-1]);
            column = column-coin[row-1];
        }
    }
    //reverse(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N; //Total Target Cents

        int n = 10; //size of coin[] array
        int coin[n];
        coin[0] = 1;
        coin[1] = 2;
        coin[2] = 5;
        coin[3] = 10;
        coin[4] = 20;
        coin[5] = 50;
        coin[6] = 100;
        coin[7] = 200;
        coin[8] = 500;
        coin[9] = 2000;
        
        vector<int> result = MinMemberUnboundedSubset(coin, N, n); //minimum number of coins to make the change
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
}
