//print the length of longest palindromic substring in a string
#include <iostream>
#include <algorithm>
using namespace std;

string LongestPalindromicSubstring(string X, string Y, int n, int m)
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
    int row = 0;
    int col = 0;
    for (int i=0; i < n+1; i++)
    {
        for (int j=0; j < m+1; j++)
        {
            if(LCS[i][j] > max)
            {
                max = LCS[i][j];
                row = i;
                col = j;
            }
        }
    }
    int len = max; //len of the longest palindromic substring at LCS[row][col]
    
    string s = "";
    if(len>=3)
    {
        while(len--)
        {
            s.push_back(X[row-1]);
            row--;
        }
        reverse(s.begin(), s.end());
        return s;
    }
    else if(len >= 1) 
    {
        string s = "";
        s.push_back(X[row-1]);
        if(X[row-2] == X[row-1]) //len 2 only can be palindrome if equal letters
        {
            s.push_back(X[row-2]);
        }
        else
        {
            s.pop_back();
            s.push_back(X[0]);
        }
        return s;
    }

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

        string ans = LongestPalindromicSubstring(X,Y,n,m);
        cout<< ans <<endl;
    }
}
