// better use 3D Matrix cuz we don't have to iteratively search in matrix as we are doing with Map.
// Optimization -> memoize at every call in the k loop too
// (For worst of edge cases) In the base condition i==j ,store value 0/1 (T/F)depending on outcome in you dp matrix & then return.
////////Passed in GFG

#include <iostream>
#include <cstring>
using namespace std;

// Better use 3D Matrix cuz we don't have to iteratively search in matrix as we are doing with Map.
int dp[1001][1001][2]; //for storing every sub-problems ans.(Memoization)

int TBP(string s, int i, int j, bool output) // here boolean output is the subproblem expression o/p
{
    if(dp[i][j][output] != -1)
        return dp[i][j][output];


    if(i>j) //invalid i/p
        return dp[i][j][output] = 0;
    if(i==j) //smallest valid i/p
    {
        if(output == true)
        {
            if(s[i] == 'T') // i& j index pointer always lies either on T or F
                return dp[i][j][output] = 1;
            else
                return dp[i][j][output] = 0;
        }
        else if(output == false)
        {
            if(s[i] == 'F')
                return dp[i][j][output] = 1;
            else
                return dp[i][j][output] = 0;
        }
    }              ////Base Condition



    int ans = 0;
    for(int k=i+1; k<=j-1; k+=2) // k breaking subproblems index pointer always lies either on char | or & or ^
    {
        int lt,rf,lf,rt;
        if(dp[i][k-1][true] != -1)
        {
            lt = dp[i][k-1][true];
        }
        else
        {
            lt = TBP(s, i ,k-1 , true);
            dp[i][k-1][true] = lt;
        }

        if(dp[k+1][j][false] != -1)
        {
            rf = dp[k+1][j][false];
        }
        else
        {
            rf = TBP(s, k+1 ,j , false);
            dp[k+1][j][false] = rf;
        }

        if(dp[i][k-1][false] != -1)
        {
            lf =  dp[i][k-1][false];
        }
        else
        {
            lf = TBP(s, i ,k-1 , false);
            dp[i][k-1][false] = lf;
        }

        if(dp[k+1][j][true] != -1)
        {
            rt = dp[k+1][j][true];
        }
        else
        {
            rt = TBP(s, k+1 ,j , true);
            dp[k+1][j][true] = rt;
        }


        //finding ans sccording to the operator, s[k], at breaking index pointer at k
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
    return dp[i][j][output] = ans%1003; //storing in value for the key in the matrix
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
