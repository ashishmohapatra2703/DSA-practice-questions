/* Given an array A containing 2*N+2 positive numbers, out of which 2*N numbers exist in pairs 
whereas the other two number occur exactly once and are distinct. 
Find the other two numbers (in sorted order).
Input: 
N = 2
arr[] = {1, 2, 3, 2, 1, 4}
Output:
3 4 
Explanation: 3 and 4 occur exactly once. */


// Time Complexity: O(N)
//Space Complexity: O(1)
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        int xXORy=0;
        for(int ele: nums)
        {
            xXORy = xXORy ^ ele;
        }
        
        int rmsbm_xXORy = (xXORy & -xXORy);
        
        int x=0;
        int y=0;
        for(int ele: nums)
        {
            if((ele & rmsbm_xXORy) == 0)
                x = x ^ ele;
            else if((ele & rmsbm_xXORy) == rmsbm_xXORy)
                y = y ^ ele;
        }
        
        vector<int> uniqueNums;
        if(x < y)
        {
            uniqueNums.push_back(x);
            uniqueNums.push_back(y);
        }
        else
        {
            uniqueNums.push_back(y);
            uniqueNums.push_back(x);
        }
        return uniqueNums;
    }
};