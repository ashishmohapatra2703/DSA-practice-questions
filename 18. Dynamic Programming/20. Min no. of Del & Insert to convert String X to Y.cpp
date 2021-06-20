//Print the total no of insertions and deletions to be done to convert str1 to str2
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
        int n; cin>>n;
        int m; cin>>m;
        string X; cin>>X;
        string Y; cin>>Y;

        int lenLCS = LenLongestCommonSubSequence(X,Y,n,m);

        int MinDelInsert = n + m - (2*lenLCS);
        cout<< MinDelInsert <<endl;
    }
}
// Min no. Deletion = n - lenLCS;
// Min no. Insertion = m - lenLCS;
