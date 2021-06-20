//Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true
// changed 4 lines in recursion code
#include <iostream>
#include <cstring>
using namespace std;

// better use 3D Matrix cuz we don't have to iteratively search in matrix as we are doing with Map.
int dp[1001][1001][2]; //for storing every sub-problems ans.(Memoization)

int TBP(string s, int i, int j, bool output) // here boolean output is the subproblem expression o/p
{
    if(i>j) //invalid i/p
        return 0;
    if(i==j) //smallest valid i/p
    {
        if(output == true)
        {
            if(s[i] == 'T') // i& j index pointer always lies either on T or F
                return 1;
            else
                return 0;
        }
        else if(output == false)
        {
            if(s[i] == 'F')
                return 1;
            else
                return 0;
        }
    }              ////Base Condition


    if(dp[i][j][output] != -1)
        return dp[i][j][output];

    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2) // k breaking subproblems index pointer always lies either on char | or & or ^
    {
        int lt = TBP(s, i ,k-1 , true);
        int rf = TBP(s, k+1 ,j , false);
        int lf = TBP(s, i ,k-1 , false);
        int rt = TBP(s, k+1 ,j , true);

        if(s[k] == '&')
        {
            if(output == true)
                ans += lt*rt;
            else if(output == false)
                ans += lt*rf + lf*rt + lf*rf;
        }
        else if(s[k] == '|')
        {
            if(output == true)
                ans += lt*rt + lt*rf + lf*rt;
            else if(output == false)
                ans += lf*rf;
        }
        else if(s[k] == '^')
        {
            if(output == true)
                ans += lt*rf + lf*rt;
            else if(output == false)
                ans += lt*rt + lf*rf;
        }
    }
    return dp[i][j][output] = ans%1003; //storing in value for the key in the unordered_map
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        int n;
        cin>>n; //str length
        string str;
        cin>>str;
        int TrueNoOfWaysParenthesize  = TBP(str, 0 ,n-1 , true); //final value of expression to be evaluated  true.
        cout<< TrueNoOfWaysParenthesize <<endl;
    }
}

