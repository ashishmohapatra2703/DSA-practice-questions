//print the length of Shortest Common SuperSequence of the two strings
#include <iostream>
#include <algorithm>
using namespace std;

string ShortestCommonSuperSequence(string X, string Y, int n, int m)
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
    int lenSCSS = n + m - LCS[n][m];//////////////////////////////////////////////////////////////////////

    string ans = "";
    int row = n;
    int column = m;
    while(row>0 && column>0)
    {
        if(LCS[row][column] == LCS[row][column-1])
        {
            ans.push_back(Y[column-1]);
            column--;
        }
        else if(LCS[row][column] == LCS[row-1][column])
        {
            ans.push_back(X[row-1]);
            row--;
        }
        else if(LCS[row][column] == LCS[row-1][column-1]+1) //matched element
        {  //DONT USE if(a[row-1] == b[column-1]) condition PROBLEM ARISES IF REPEITION OF SIMILAR ELEMENT HAPPENS
            ans.push_back(X[row-1]); //OR ans.push_back(Y[column-1]);
            row--;
            column--;
        }
    }
    while(row>0)
    {
        ans.push_back(X[row-1]);
        row--;
    }
    while(column>0)
    {
        ans.push_back(Y[column-1]);
        column--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
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

        string SCSS = ShortestCommonSuperSequence(X,Y,n,m);
        cout<< SCSS <<endl;
    }
}
