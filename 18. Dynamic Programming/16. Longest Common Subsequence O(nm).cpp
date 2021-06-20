// T.C = O(n.m)
// S.C = O(n.m)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int LenLongestCommonSubSequence(vector<int> a, vector<int> b)
{
    int n = a.size();
    int m = b.size();
    vector<vector<int>> LCS ( n+1 , vector<int> (m+1));
    for (int i=0; i < n+1; i++)
    {
        for (int j=0; j < m+1; j++)
        {
            if(i==0 || j==0)
                LCS[i][j] = 0;
            
            else if(a[i-1] == b[j-1]) //match found
            {
                LCS[i][j] = LCS[i-1][j-1] + 1;
            }
            else//(a[i-1] != b[j-1])
            {
                LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
            }
        }
    }//LCS[n][m] contains length of LCS for a[0..n-1] and b[0..m-1]
    return LCS[n][m];
}

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
    }
    vector<int> b(m);
    for (int j = 0; j < m; j++)
    {
        cin>>b[j];
    }
    int result = LenLongestCommonSubSequence(a, b);
    cout<< result <<endl;
    return 0;
}
