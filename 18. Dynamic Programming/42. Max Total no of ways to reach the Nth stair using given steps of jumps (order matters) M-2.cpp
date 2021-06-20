//There are N stairs, a person standing at the bottom wants to reach the top.
//The person can climb either 1 stair or 2 stairs at a time.
//Count the number of ways, the person can reach the top (order does matter).

//Efficient Solution--->
//it was giving TLE because for every test case it is computing dp for 10^5 
//the better way to store dp just once globally

//Note:-  it becomes fibonacci series ; if given step[] = [1,2]
#include <iostream>
using namespace std;
long long mod= 1000000007;

long long dp[100001] = {0}; //Constraints: 1 <= N <= 10^5

void CountUnBoundedSubsetSum_WithPemutatedSubsets()
{
    dp[0] = 1; //dp[0] -> phi -> 1 way
    dp[1] = 1; //dp[1] -> only single 1 steps can be taken to reach the top stair
    
    for (int i=2; i<100001; i++)
    {
        dp[i] = (dp[i-1] + dp[i-2])%mod; //dp[i] += dp[i-steps[m]]; // according the staircase climbing diagram in copy
    }
}
int main()
{
    int t;
    cin>>t;
    CountUnBoundedSubsetSum_WithPemutatedSubsets();
    while(t--)
    {
        //here steps[2] array = 1, 2
        int N;
        cin>>N; //Top ~ Total No. of Steps

        long long NoOfWays = dp[N];
        cout<< NoOfWays <<endl; 
    }
}
/*
Input: N = 4
Output: 5
Explantion:
Below are the four ways
 1 step + 1 step + 1 step + 1 step
 1 step + 2 step + 1 step
 2 step + 1 step + 1 step 
 1 step + 1 step + 2 step
 2 step + 2 step
 */

//OR   recursion + memoization
class Solution {
public:
    vector<int> dp {vector<int>(50, -1)};   // n according to Constraints
    int climbStairs(int n) 
    {
        if(n == 0 || n == 1)
            return 1;
        
        if(dp[n] != -1)
            return dp[n];
        
        return dp[n] = climbStairs(n-1) + climbStairs(n-2);
    }
};




// if user i/p steps[] given :-

//Given a set of m distinct positive integers and a value ‘N’.
//The problem is to count the total number of ways we can form ‘N’ by doing sum of the array elements. 
//Repetitions and different arrangements are allowed.

#include <iostream>
#include <cstring>
using namespace std;
unsigned long long mod = 1000000007;

long long CountUnBoundedSubsetSum_WithPemutatedSubsets(int steps[], int n, int N)
{
    long long dp[N+1];
    memset(dp, 0, sizeof(dp));
    
    dp[0] = 1; //dp[0] -> phi -> 1 way
    
    for(int i=1; i<N+1; i++)
    {
        for(int m=0; m<n; m++) //for iteration through steps[] array values 
        {
            if(i-steps[m] >= 0) //validation of index
                dp[i] = (dp[i] + dp[i-steps[m]])%mod; //equation according the staircase climbing diagram in copy
        }
    }
    return dp[N];
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; //size of steps[] array
        cin>>n;
        
        int N;
        cin>>N; //Sum Value
        
        int steps[n];
        for(int i=0; i<n; i++)
        {
            cin>>steps[i];
        }

        int NoOfWays = CountUnBoundedSubsetSum_WithPemutatedSubsets(steps, n, N); 
        cout<< NoOfWays <<endl; //With Different Arrangement/Order of each Subset
    }
}
/*
Input: N = 7 and steps[] = {1,5,6}
Output: 6
 1 + 1 + 1 + 1 + 1 + 1 + 1
 1 + 1 + 5
 1 + 5 + 1
 5 + 1 + 1
 6 + 1
 1 + 6
 */