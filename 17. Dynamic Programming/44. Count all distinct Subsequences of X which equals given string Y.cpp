//Count all possible Distinct subsequences present in string X that are == “GEEKS”

//OR the no. of ways in which the subsequence Y=“GEEKS” can be formed from the string S

//OR Print the number of times Y appears in X (as its subseq.), whether continuous or discontinuous. 
#include <iostream>
using namespace std;
#define mod 1000000007;

int CountSubSequencesOfX_whichEqualsY(string X, string Y, int n, int m)
{
    int dp[m+1][n+1]; //here row ~ 6  (m=5)   //& column ~ X.length()+1
        
    for (int i=0; i < m+1; i++)
    {
        for (int j=0; j < n+1; j++)
        {
            if(j==0)
                dp[i][j] = 0;
            if(i==0)
                dp[i][j] = 1;  
        }
    }
    for (int i=1; i < m+1; i++)
    {
        for (int j=1; j < n+1; j++)
        {
            if(Y[i-1] == X[j-1])//form subsequences in X to match with Y[0 .... i-1]
            {
                dp[i][j] = dp[i][j-1] + dp[i-1][j-1]; 
            }   
            else
            {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    /*for (int i=0; i < m+1; i++)
    {
        for (int j=0; j < n+1; j++)
        {
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }*/
    return dp[m][n]%mod;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        string X; cin>>X;
        
        string Y = "GEEKS";
        int m = Y.length();

        int num = CountSubSequencesOfX_whichEqualsY(X,Y,n,m);
        cout<< num <<endl;
    }
}
