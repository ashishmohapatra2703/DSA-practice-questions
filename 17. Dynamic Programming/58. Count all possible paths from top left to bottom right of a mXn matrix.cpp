/*The task is to count all the possible paths from top left to bottom right of a m X n matrix 
with the constraints that from each cell you can either move only to right or down.
Input: m = 3, R = 3
Output: 6
Explanation: Six possible ways are
RRDD, DDRR, RDDR, DRRD, RDRD, DRDR.    */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
  public:
    long long int mod = 1000000007;
    vector<vector<long long>> dp {101, vector<long long>(101,-1)};
    
    long long int numberOfPaths(int m, int n)
    {
        if(m == 1 || n == 1)
            return 1;
        
        if(dp[m][n] != -1)
            return dp[m][n];
            
        return dp[m][n] = (numberOfPaths(m-1, n) + numberOfPaths(m, n-1)) % mod;

    /*  long long right;     //more optimization
        long long down;
        
        if(dp[m-1][n] != -1){
            right = dp[m-1][n];
        }
        else
        {
            right = numberOfPaths(m-1, n);
            dp[m-1][n] = right;
        }
        
        if(dp[m][n-1] != -1){
            down = dp[m][n-1];
        }
        else
        {
            down = numberOfPaths(m, n-1);
            dp[m][n-1] = down;
        }
            
        return dp[m][n] = (right + down) % mod; */
    }
};

int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        int n, m;
        cin >> m >> n;
        
        Solution ob;
        cout<<ob.numberOfPaths(m,n)<<endl;
    }
}