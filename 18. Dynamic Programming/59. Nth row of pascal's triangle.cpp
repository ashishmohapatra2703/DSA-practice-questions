/*Input: N = 4
Output: 1 3 3 1

Input:  N = 5
Output: 1 4 6 4 1  => nC0 nC1 nC2 nC3 .... nCn (where n= N-1 =4)    */

class Solution{
public:
    ll mod = 1e9+7;
    vector<vector<ll>> dp {1001 , vector<ll>(1001, -1)};
    
    ll combination(int m, int r)
    {
        if(r==0 || m==r)
            return 1;
        
        if(dp[m][r] != -1)
            return dp[m][r];

        return dp[m][r] = (combination(m-1,r-1) + combination(m-1,r))%mod;
    }
    vector<ll> nthRowOfPascalTriangle(int n) 
    {
        vector<ll> nthRow;
        for(int i=0; i<=n-1; i++)
        {
            nthRow.push_back( combination(n-1, i) );
        }
        return nthRow;
    }
};