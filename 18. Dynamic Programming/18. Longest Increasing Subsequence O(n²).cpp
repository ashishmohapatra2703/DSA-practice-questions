//////// M-1

//find length of largest increasing sub-sequence in the string (NO DUPLICATES IN IT)
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
        
        //string Y(X);
        //sort(Y.begin(), Y.end()); //it will not consider LCS having duplicates
        
        string Y = "abcdefghijklmnopqrstuvwxyz";
        
        int n = X.length();
        int m = Y.length();//26

        int lenLIS = LenLongestCommonSubSequence(X,Y,n,m);
        cout<< lenLIS <<endl;
    }
}
// i/p:   "pcbhdbjcvhjsdjhvczvd"
// sort:  "bbcccdddhhhjjjpsvvvz"
// LCS:   "bbchjjvv"  ------------->wrong o/p accor. to question

// i/p:     "pcbhdbjcvhjsdjhvczvd"
// alphasort: "abcdefghijklmnopqrstuvwxyz"
// LCS:     "bchjsvz"          



//////// M-2

//T.C = O(n²)
//S.C = O(n)
//https://youtu.be/mouCn3CFpgg
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int longestIncreasingSubsequence(vector<int> arr,int n) 
{
    int *LIS = new int[n];
    for(int i=0; i<n; i++)
    { 
        LIS[i] = 1; //every single element is increasing subseq. of length 1
    }
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            if((arr[j] < arr[i]))
            {
                LIS[i] = max(LIS[i] , 1+LIS[j]);
            }
        }
    }
    //LIS[i] stores the lenLIS ending with arr[i]
    int max = 0;
    for(int i=0; i<n; i++)
    {
        if(LIS[i]>max)
            max = LIS[i];
    }
    return max;
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int result = longestIncreasingSubsequence(arr,n);
    cout<< result <<endl;
    return 0;
}


