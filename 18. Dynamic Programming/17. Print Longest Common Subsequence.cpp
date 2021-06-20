// T.C = O(n.m)
// S.C = O(n.m)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b)
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
//in order to find the common subsequence we have to trace back from that square
//from right bottom corner in LCS i.e,LCS[n][m]
//& see where the matches are and add them to word common_subsequence
    int length = LCS[n][m]; /////////////////

    vector<int> ans;
    int row = n;
    int column = m;
    while(row>0 && column>0)
    {
        if(LCS[row][column] == LCS[row][column-1])
            column--;
        else if(LCS[row][column] == LCS[row-1][column])
            row--;
        else if(LCS[row][column] == LCS[row-1][column-1]+1) //matched element
        {  //DONT USE if(a[row-1] == b[column-1]) PROBLEM ARISES IF REPEITION OF SIMILAR ELEMENT HAPPENS
            ans.push_back(a[row-1]); //OR ans.push_back(b[column-1]);
            row--;
            column--;
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    vector<int> result = longestCommonSubsequence(a, b);
    for (int i = 0; i < result.size(); i++)
    {
        cout<< result[i];
        if(i != result.size()-1)
            cout<<" ";
    }
    return 0;
}
