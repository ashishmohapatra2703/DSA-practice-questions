//Determine the fewest cuts needed for palindrome partitioning of a given string.
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1001][1001]; //global declaration//acor. to constraints of i&j ,i.e, size of the string

bool isPalindrome(string str, int f, int b)
{
    while(f<b)
    {
        if(str[f] != str[b])
            return false;
        f++;
        b--;
    }
    return true;
}

int MinCutPP(string str, int i, int j)
{
    if(i>=j) //empty str OR single char, both requires 0 cut for PP
        return 0;
    if(isPalindrome(str,i,j) == true)
        return 0;   //both are the base condition

    if(dp[i][j] != -1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++) //movement of k
    {
        int tempans = MinCutPP(str,i,k) + MinCutPP(str,k+1,j) + 1;
        //break into adding 2 function calls with proper boundary conditions and add with 3rd term i.e, the 1 cut itself

        ans = min(ans, tempans);
    }
    return dp[i][j] = ans; //store in the matrix
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        string str;
        cin>>str;
        int MinCutPalindromePartitioning = MinCutPP(str, 0 ,str.length()-1); //find proper i and j values for main functuon call
        cout<< MinCutPalindromePartitioning <<endl;
    }
}
