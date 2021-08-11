/*Given an array of integers cost[] of length N, 
where cost[i] is the cost of the ith step on a staircase. 
*** Once you pay the cost, you can either climb one or two steps. ***
You can either start from the step with index 0, or the step with index 1.
Return the minimum cost to reach the top of the floor (Nth index) , by climbing N stairs. 

Input: N = 3  cost[] = {10, 15, 20}
Output: 15
Explanation: Cheapest option is to start at cost[1], pay that cost, and go to the top.

Input: N = 10  arr[] = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1}
Output: 6
Explanation: Cheapest option is to start on cost[0], and only step on 1s, skipping cost[3].*/

//M-1 	T.C = O(n) , S.C = O(n)
class Solution {
public:
    int minCostClimbingStairs(vector<int>&cost ,int N) 
    {
        int dp[N+1] = {0};

        dp[1] = cost[0];
       
        for(int i=2; i<=N; i++)
        {
            dp[i] = cost[i-1] + min(dp[i-1], dp[i-2]);
        }
        //dp[i] = min cost to reach (i-1)th indexed stair 
        
        return min(dp[N], dp[N-1]);
    }
};
//finally 2 options , we choose min. b/w
//1) at N-1 indexed stair, pay cost[N-1] i.e, jump 1 step and reach the top (~ dp[N])
//2) at N-2 indexed stair, pay cost[N-2] i.e, jump 2 steps and reach the top (~ dp[N-1])


//M-2 	T.C = O(n) , S.C = O(1)
class Solution {
public:
    int minCostClimbingStairs(vector<int>&cost ,int N) 
    {
        int dpFirst = 0;
        int dpSecond = cost[0];
       
        for(int i=2; i<=N; i++)
        {
            int dpAti = cost[i-1] + min(dpFirst, dpSecond);
            
            dpFirst = dpSecond;
            dpSecond = dpAti;
        }
        //dp[i] = min cost to reach (i-1)th indexed stair 
        
        return min(dpSecond, dpFirst);
    }
};