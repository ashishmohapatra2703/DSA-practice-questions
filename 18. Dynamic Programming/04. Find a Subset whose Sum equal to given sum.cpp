#include <iostream>
using namespace std;

bool isSubsetSum(int arr[],int sum,int n)
{
    bool dp[n+1][sum+1]; // Build table dp[n+1][W+1] in bottom up manner
    for (int i=0; i<n+1; i++)
    {
        for (int j=0; j<sum+1; j++)
        {
            if(i==0) //Base Condition initialization
                dp[i][j] = false;
            if(j==0) //Base Condition initialization
                dp[i][j] = true;
        }
    }
    for (int i=1; i<n+1; i++)
    {
        for (int j=1; j<sum+1; j++)
        {
            if(arr[i-1] <= j)
                dp[i][j] =  dp[i-1][j-arr[i-1]] || dp[i-1][j] ;
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
    } */
    return dp[n][sum];
}
int main()
{
    int arr[] = { 2,3,7,8,10 };
    int sum = 11;
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = isSubsetSum(arr,sum,n);  // Returns true if there is a subset of arr[] with sum equal to given sum
    if(ans)
        cout<<"\nFound a subset with given sum"<<endl;
    return 0;
}
//  Time Complexity: O(sum*n), where sum is the ‘target sum’ and ‘n’ is the size of array.
//  Auxiliary Space: O(sum*n), as the size of 2-D array is sum*n.

//subset can be non-contiguous
//sub-array must be contiguous
