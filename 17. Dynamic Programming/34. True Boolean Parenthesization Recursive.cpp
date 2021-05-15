//Count the number of ways we can parenthesize the expression so that the value of expression evaluates to true
#include <iostream>
using namespace std;

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
    return ans;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; //str length
        string str;
        cin>>str;
        int TrueNoOfWaysParenthesize  = TBP(str, 0 ,n-1 , true); //final value of expression to be evaluated  true.
        cout<< TrueNoOfWaysParenthesize <<endl;
    }
}
