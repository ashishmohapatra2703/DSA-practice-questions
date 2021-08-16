/*Given an array of distinct integers nums and a target integer target, 
return the number of possible combinations that add up to target.
The answer is guaranteed to fit in a 32-bit integer.

Input: nums = [1,2,3], target = 4
Output: 7
Explanation: The possible combination ways are:
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
Note that different sequences are counted as different combinations.  	*/

//CountUnBoundedSubsetSum_WithPemutatedSubsets
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) 
    {
        int setSize = nums.size();
        unsigned long long dp[target+1];
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        
        for(int i=1; i<=target; i++)
        {
            for(int k=0; k<=setSize-1; k++)
            {
                if(i-nums[k] >=0)
                    dp[i] += dp[i-nums[k]];
            }
        }
        return dp[target];
    }
};

//Similar Question  (Staircase Problem) 
/*There are n stairs, a person standing at the bottom wants to reach the top. 
The person can climb either 1 stair or 2 stairs at a time. 
Count the number of ways, the person can reach the top n'th stair (order does matter).

Input: n = 4
Output: 5
Explanation:
You can reach 4th stair in 5 ways. 
Way 1: Climb 2 stairs at a time. 
Way 2: Climb 1 stair at a time.
Way 3: Climb 2 stairs, then 1 stair and then 1 stair.
Way 4: Climb 1 stair, then 2 stairs then 1 stair.
Way 5: Climb 1 stair, then 1 stair and then 2 stairs. 

here set/steps[] = {1, 2} , setSize = 2  and target = n  */


//Similar Question 
/*A frog jumps either 1, 2, or 3 steps to go to the top. 
In how many ways can it reach the top.
Input:
N = 4
Output: 7
Explanation: Below are the 7 ways to reach 4
1 step + 1 step + 1 step + 1 step
1 step + 2 step + 1 step
2 step + 1 step + 1 step
1 step + 1 step + 2 step
2 step + 2 step
3 step + 1 step
1 step + 3 step     */