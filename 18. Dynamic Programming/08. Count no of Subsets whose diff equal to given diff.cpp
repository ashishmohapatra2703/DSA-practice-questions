//Partition into 2 sub-sets
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
    return dp[n][sum];
}
int main()
{
    int arr[] = { 1,1,1,1 };
    int diff = 2;
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum_arr=0;
    for(int i=0; i<n; i++)
    {
        sum_arr += arr[i];
    }

    if(diff > sum_arr) //all >=0 positive number given
        cout<<"\nNo partition of subsets with given diff= "<<diff<<endl;
    else if((diff+sum_arr)%2 != 0)
        cout<<"\nNo partition of subsets with given diff= "<<diff<<endl;
    else
    {
        int sum = (diff+sum_arr)/2;
        int ans = CountSubsetSum(arr,sum,n);  // Returns count no. of subsets of arr[] with sum equal to given sum
        if(ans)
            cout<<"\nFound "<<ans<<" instance where partition of subsets whose diff = "<<diff<<endl;
        else
            cout<<"\nNo partition of subsets with given diff= "<<diff<<endl;
    }
}
//      s1-s2 = diff      equation 1
//and   s1+s2 = sum_arr   equation 2
// ----------------------------------------
//  =>  2s1 = sum+diff
//   => s1 = (sum+diff)/2
//So, if (sum+diff) is even then only finding s1 is possible.

