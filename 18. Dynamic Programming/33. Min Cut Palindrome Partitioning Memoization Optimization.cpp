//Determine the fewest cuts needed for palindrome partitioning of a given string.
#include <iostream>
#include <climits>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1005][1005]; //global declaration//acor. to constraints of i&j ,i.e, size of the string

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
    if(dp[i][j] != -1) //MinCutPP(str, i, j) solved previously so return the stored value
        return dp[i][j];


    if(i>=j) //empty str OR single char, both requires 0 cut for PP
        return dp[i][j] = 0;

    //the actual problem is caused by placing ispalindrom() before checking the stored solution
    //{i.e., whether you've already solved a subproblem or not, ispalindrom() will always gonna execute for each recursion}.
    //So just bring ispalindrom () down after if( dp[i][j]!=-1){...}

    if(isPalindrome(str,i,j) == true)
        return dp[i][j] = 0;

    //else MinCutPP(str, i, j) NOT solved previously and //if(dp[i][j] == -1)

    //here check both left & right subproblem are solved previously & stored in matrix
            //OR NOT, if NOT so then do recursive call & store in the matrix

    int ans = INT_MAX;
    for(int k=i; k<=j-1; k++) //movement of k
    {
        int left,right;
        if(dp[i][k] != -1)
        {
            left = dp[i][k];
        }
        else
        {
            left = MinCutPP(str,i,k);
            dp[i][k] = left;
        }

        if(dp[k+1][j] != -1)
        {
            right = dp[k+1][j];
        }
        else
        {
            right = MinCutPP(str,k+1,j);
            dp[k+1][j] = right;
        }

        int tempans = left + right + 1;
        //here 1 is for doing current cut to break i,j to (i to k) and (k+1 to j)
        ans = min(ans, tempans);
    }
    return dp[i][j] = ans; //store MinCutPP(str, i, j) ans value in the matrix and retrun
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
