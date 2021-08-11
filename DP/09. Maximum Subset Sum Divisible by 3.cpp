/*Given an array nums of integers, we need to find the maximum possible sum 
of elements of the array such that it is divisible by three.

Input: nums = [3,6,5,1,8]
Output: 18
Explanation: Pick numbers 3, 6, 1 and 8 their sum is 18 (maximum sum divisible by 3).

Constraints:
1 <= nums.length <= 4 * 10^4
1 <= nums[i] <= 10^4        */

class Solution {
public:
    int maxSumDivThree(vector<int>& nums) 
    {
        int n = nums.size();
        int mSRdp[n+1][3]; //dp[i][j] = Max subset sum using first i elements of nums, that has %3 = j
        //mSRdp = maxSubsetSumwithRemainderDP
        memset(mSRdp, 0, sizeof(mSRdp));
        
        for(int i=1; i<=n; i++)
        {
            if(nums[i-1]%3 == 0)
            {
                mSRdp[i][0] = max(mSRdp[i-1][0] , nums[i-1]+mSRdp[i-1][0]);
                mSRdp[i][1] = (mSRdp[i-1][1]) ? max(mSRdp[i-1][1] , nums[i-1]+mSRdp[i-1][1]) : mSRdp[i-1][1];
                mSRdp[i][2] = (mSRdp[i-1][2]) ? max(mSRdp[i-1][2] , nums[i-1]+mSRdp[i-1][2]) : mSRdp[i-1][2];
            }
            else if(nums[i-1]%3 == 1)
            {        
                mSRdp[i][0] = (mSRdp[i-1][2]) ? max(mSRdp[i-1][0] , nums[i-1]+mSRdp[i-1][2]) : mSRdp[i-1][0];   
                mSRdp[i][1] = max(mSRdp[i-1][1] , nums[i-1]+mSRdp[i-1][0]);
                mSRdp[i][2] = (mSRdp[i-1][1]) ? max(mSRdp[i-1][2] , nums[i-1]+mSRdp[i-1][1]) : mSRdp[i-1][2];
            }
            else if(nums[i-1]%3 == 2)
            {
                mSRdp[i][0] = (mSRdp[i-1][1]) ? max(mSRdp[i-1][0] , nums[i-1]+mSRdp[i-1][1]) : mSRdp[i-1][0];   
                mSRdp[i][1] = (mSRdp[i-1][2]) ? max(mSRdp[i-1][1] , nums[i-1]+mSRdp[i-1][2]) : mSRdp[i-1][1];
                mSRdp[i][2] = max(mSRdp[i-1][2] , nums[i-1]+mSRdp[i-1][0]);
            }
        }
        
        return mSRdp[n][0];
    }
};