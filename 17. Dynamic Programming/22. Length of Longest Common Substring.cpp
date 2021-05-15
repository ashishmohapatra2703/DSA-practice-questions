//print the length of longest  common substring of the two strings
#include <iostream>
using namespace std;

int LenLongestCommonSubstring(string X, string Y, int n, int m)
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
            if(X[i-1] == Y[j-1]) //match found
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else//(a[i-1] != b[j-1])
            {
                LCS[i][j] = 0;
            }
        }
    }

    int max = 0;
    for (int i=0; i < n+1; i++)
    {
        for (int j=0; j < m+1; j++)
        {
            if(LCS[i][j] > max)
                max = LCS[i][j];
        }
    }
    return max;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int m; cin>>m;
        string X; cin>>X;
        string Y; cin>>Y;

        int ans = LenLongestCommonSubstring(X,Y,n,m);
        cout<< ans <<endl;
    }
}
