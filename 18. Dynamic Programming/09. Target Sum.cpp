//Given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -.
//For each integer, you should choose one from + and - as its new symbol.
//Find out how many ways to assign symbols to make sum of integers equal to target S.

#include <iostream>
#include <cmath>
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
            else if((arr[i-1] > j)  ||  (arr[i-1] == 0))
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][sum];
}
int main()
{
    int arr[] = { 2,1,2 };
    int target = 1;
    int n = sizeof(arr) / sizeof(arr[0]);

    int sum_arr=0;
    int zero_count = 0;
    for(int i=0; i<n; i++)
    {
        sum_arr += arr[i];
        if(arr[i] == 0)
            zero_count ++;
    }

    if(target > sum_arr) // all non-negative integers given
        cout<<"\nNo ways found to have result of arr[] target= "<<target<<endl;
    else if((target+sum_arr)%2 != 0)
        cout<<"\nNo ways found to have result of arr[] target= "<<target<<endl;
    else
    {
        int sum = (target+sum_arr)/2; //int sum = sum of s1 partition subset of arr[]

        int ans = CountSubsetSum(arr,sum,n);  // Returns count no. of subsets of arr[] with sum equal to given sum
        ans = pow(2,zero_count)*ans;

        if(ans)
            cout<<"\nFound "<<ans<<" ways to assign symbols to make sum of integers equal to target = "<<target<<endl;
        else
            cout<<"\nNo ways found to have result of arr[] target= "<<target<<endl;
    }
}
// THE SAME SHOULD BE ALSO DONE IN PREV QUE. Count of subsets whose target. = given target. ; if non-negative integers given in arr[]
//THESE 2 QUES. ARE EXACTLY THE SAME


//zero_count is for '0's in the array.
//If we have n number of zeroes then we need to multiply our result of "count of subsets with a sum" to 2^n.
//And we need to not consider this while calculating in bottom-up manner,
//hence the case " if(nums[i-1]==0) { dp[i][j] = dp[i-1][j] } ".


//For example: If we have 2(zero_count=2) zeroes in the example array for which we calculate count of subset with a sum
// then there are 4(2^zero_count) ways that is
// either selecting first zero,
// second selecting second 0 present in array,
// third not selecting both,
// fourth selecting both.

