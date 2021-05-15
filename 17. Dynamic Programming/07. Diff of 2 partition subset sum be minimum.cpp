//hard gfg
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
                dp[i][j] = ( dp[i-1][j-arr[i-1]] || dp[i-1][j] );
            else if(arr[i-1] > j)
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
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
        for (int i=0; i<n; i++)  cin>>arr[i];

        int sum_arr=0;
        for (int i=0; i<n; i++)
        {
            sum_arr += arr[i];
        }

        int half_range = sum_arr/2;
        while(true)
        {
            bool ans = isSubsetSum(arr,half_range, n);
            if(ans)                // half_range is the possible subset sum of s1
            {
                cout<< (sum_arr-(2*half_range)) <<endl;
                break;
            }
            else
                half_range--;
        }
    }
}
//             |(s2 - s1)| -> min.
//          => |(sum_arr - 2*s1)| -> min.
//          =>  (sum_arr - 2*s1) -> min.
//              where s1 is belongs to possible values belonging in [ 0 to half_range ]
//          =>  s1 -> max.
//          hence start check from half_range & --  so that s1 could be max. in its interval.
