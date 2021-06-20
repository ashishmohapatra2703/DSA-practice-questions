#include <iostream>
using namespace std;

int CountSubsetSum(int arr[],int sum,int n)
{
    int dp[n+1][sum+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            if(i==0) //Base Condition initialization
                dp[i][j] = 0;
            if(j==0) //Base Condition initialization
                dp[i][j] = 1;
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] =  dp[i-1][j-arr[i-1]] + dp[i-1][j] ;
            else if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    /*
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            cout<<dp[i][j]<<"  ";
        }
        cout<<endl;
    }*/
    return dp[n][sum];
}
int main()
{
    int arr[] = { 3,3,3,3 };
    int sum = 6;
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = CountSubsetSum(arr,sum,n);  // Returns no. of subsets of arr[] with sum equal to given sum
    if(ans)
        cout<<"\nFound "<<ans<<" subsets with given sum = "<<sum<<endl;
    else
        cout<<"\nNo subsets found with given sum= "<<sum<<endl;
    return 0;
}
// NO multiple occurrence of the same item i.e., variation of unbounded knapsack
