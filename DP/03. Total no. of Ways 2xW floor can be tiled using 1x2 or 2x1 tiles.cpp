/* Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, 
the task is to find the number of ways the floor can be tiled. A tile can 
either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile.
Print the answer modulo 109+7.

Input:  W = 4
Output:  5
Explanation:
For a 2 x 4 board, there are 5 ways
1) All 4 vertical
2) All 4 horizontal
3) First 2 vertical, remaining 2 horizontal.
4) First 2 horizontal, remaining 2 vertical.
5) Corner 2 vertical, middle 2 horizontal. 		*/


//CountUnBoundedSubsetSum_WithPemutatedSubsets
class Solution {
private:
    long long mod= 1000000007;
public:
    long long numberOfWays(long long N) 
    {
        long long dp[N+1];
        dp[0] = 1; //dp[0] -> phi -> 1 way
        dp[1] = 1; 
        
        for(long long i=2; i<=N; i++)
        {
            dp[i] = (dp[i-1] + dp[i-2]) %mod; //dp[i] += dp[i-steps[m]]; //if more sets of tiles given
        }
        
        return dp[N];
    }
};