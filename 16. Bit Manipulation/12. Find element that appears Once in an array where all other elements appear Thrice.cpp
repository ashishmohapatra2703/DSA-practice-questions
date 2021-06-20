/* Given an integer array nums where every element appears three times except for one, 
which appears exactly once. Find the single element and return it.
Input: nums = [51,57,51,57,63,38,57,63,63,51]
Output: 38

Constraints:
1 <= nums.length <= 3 * 104
-2^31 <= nums[i] <= 2^31 - 1  */

//M-1  Time Complexity = O(32.n)
class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
        int uniqueNum = 0;

        for(int i=0; i<32; i++)
        {
            int SetBitsInithIdx = 0;
            for(int n : nums)
            {
                if( (n & (1<<i)) != 0 ) //checking if set or not
                    SetBitsInithIdx++;
            }

            if(SetBitsInithIdx % 3 != 0)
            	uniqueNum = uniqueNum | (1<<i); //setting
            else
                uniqueNum = uniqueNum & ~(1<<i); //unsetting
        }

        return uniqueNum;
    }
};

//M-2  Time Complexity = O(n)