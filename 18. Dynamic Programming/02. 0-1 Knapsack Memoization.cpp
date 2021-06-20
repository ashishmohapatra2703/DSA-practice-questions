/* //Memoization //top-down approach of dynamic programming
creating a 2-D array that can store a particular state (n, w) if we get it the first time.
Now if we come across the same state (n, w) again instead of calculating it in exponential complexity
we can directly return its result stored in the table in constant time.
*/
#include <iostream>
#include <algorithm>
using namespace std;

//OR globally vector<vector<int>> dp(101 , vector<int>(1001, -1) ); //acor. to constraints//NO need to pass as parameter in the func. then

int knapSack(int wt[],int val[],int W,int n,vector<vector<int>> dp) //T.C = O(n*W)
{
    if(n==0 || W==0) //Base Condition //smallest valid i/p
        return 0;

    if(dp[n][W] != -1)
        return dp[n][W];
    if(wt[n-1] <= W) //star from end element
        return dp[n][W] = max(val[n-1]+knapSack(wt,val,W-wt[n-1],n-1,dp) , knapSack(wt,val,W,n-1,dp)); //Return the maximum of two cases: (1) nth item included (2) not included
    else if(wt[n-1] > W) //this item cannot be included in the optimal solution
        return dp[n][W] = knapSack(wt,val,W,n-1,dp); // Store the value of function call stack in table dp[n][W] before return
}
int main()
{
    int val[] = { 80,110,70 };
    int wt[] = { 10, 20, 30 };
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    
    static vector<vector<int>> dp( n+1 , vector<int>(W+1, -1) );
    cout << knapSack(wt,val,W,n,dp);  //Returns the value of maximum profit //190
    return 0;
}
