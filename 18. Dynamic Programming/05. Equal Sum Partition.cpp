//Print YES if the given set can be partitioned into two subsets such that the sum of elements in both subsets is equal, else print NO.
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
    for(int t_itr=0; t_itr<t; t_itr++)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        int sum_arr = 0;
        for(int i=0; i<n; i++)
        {
            sum_arr += arr[i];
        }

        if(sum_arr%2 != 0) //odd
        {
            cout<<"NO"<<endl;
        }
        else //if sum_arr is even
        {
            bool ans = isSubsetSum(arr, sum_arr/2, n);  // Returns true if there is a subset of arr[] with sum equal to given (sum_arr/2)
            if(ans)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;
        }
    }
}
// Equal Sum partition
// s1+s2 == sum_arr    --(1)
// s1 == s2            --(2)
