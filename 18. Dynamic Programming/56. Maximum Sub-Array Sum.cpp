//Run Time Error in gfg
#include <iostream>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int Kadanes_Algorithm(int arr[], int n) 
{
    int dp[n+1][n+1];
    memset(dp, 0, sizeof(dp));
    
    int MaxSubArrSum = INT_MIN;
    for(int i=1; i<n+1; i++)
    {
        for(int j=i; j<n+1; j++)
        {
            dp[i][j] = dp[i][j-1] + arr[j-1];
            MaxSubArrSum = max(MaxSubArrSum, dp[i][j]);
        }
    }
    return MaxSubArrSum;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
            
        int MaxSubArraySum = Kadanes_Algorithm(arr, n);
        cout<< MaxSubArraySum <<endl;
    }
}