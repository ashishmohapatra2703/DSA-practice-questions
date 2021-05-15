#include <iostream>
using namespace std;

int LenLongestRepeatingSubSequence(string X, string Y, int n, int m)
{
    int LCS[n+1][m+1];
    for (int i=0; i < n+1; i++)
    {
        for (int j=0; j < m+1; j++)
        {
            if(i==0 || j==0) //Base condition initialization
                LCS[i][j] = 0;
        }
    }
    for (int i=1; i < n+1; i++)
    {
        for (int j=1; j < m+1; j++)
        {
            if(X[i-1]==Y[j-1] && i!=j) //cross-matching found
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else
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
        int n; cin>>n; //int n = X.length();
        string X; cin>>X;

        int ans = LenLongestRepeatingSubSequence(X,X,n,n);
        cout<< ans <<endl;
    }
}
