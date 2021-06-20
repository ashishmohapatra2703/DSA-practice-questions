//print the min. no. of deletions required to make the string into a palindrome.
#include <iostream>
#include <algorithm>
using namespace std;

int LenLongestCommonSubSequence(string X, string Y, int n, int m)
{
    int LCS[n+1][m+1];
    for (int i=0; i < n+1; i++)
    {
        for (int j=0; j < m+1; j++)
        {
            if(i==0 || j==0)
                LCS[i][j] = 0;
        }
    }
    for (int i=1; i < n+1; i++)
    {
        for (int j=1; j < m+1; j++)
        {
            if(X[i-1] == Y[j-1]) //match found
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else//(X[i-1] != Y[j-1])
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }
    return LCS[n][m];
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string X; cin>>X;

        string Y(X); //Take a copy of the original string,
        reverse(Y.begin(), Y.end()); //then use reverse() function in <algorithm> to in-place reverse the copy.

        int n = X.length();
        int m = Y.length();

        int lenLPS = LenLongestCommonSubSequence(X,Y,n,m); // lenLPS -> Length of Longest Palindromic Subsequence

        int MinDelToPalind = n - lenLPS;
        cout<< MinDelToPalind <<endl;
    }
}
