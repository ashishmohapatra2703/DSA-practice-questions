   // print 1 if X is sub-sequences of Y else print 0.
/*
#include <iostream>
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
        string X; cin>>X;
        string Y; cin>>Y;
        int n = X.length();
        int m = Y.length();

        int lenLCS = LenLongestCommonSubSequence(X,Y,n,m);

        if(lenLCS == n)
            cout<<"1"<<endl; // X is a subsequence of Y
        else
            cout<<"0"<<endl;
    }
    return 0;
}
*/

//Easy Method T.C = O(n)
#include <iostream>
using namespace std;

bool isSubSequence(string X, string Y, int n, int m)
{
    int i=0;
    for (int j=0; i<n&&j<m ; j++)
    {
        if(X[i] == Y[j])
            i++;
    }
    if(i==n)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string X; cin>>X;
        string Y; cin>>Y;
        int n = X.length();
        int m = Y.length();

        if( isSubSequence(X,Y,n,m) )
            cout<<"1"<<endl; // X is a subsequence of Y
        else
            cout<<"0"<<endl;
    }
}
