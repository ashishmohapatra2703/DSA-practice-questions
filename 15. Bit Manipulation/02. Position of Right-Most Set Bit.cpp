/*Given an integer an N. The task is to return the position of first set bit found from the right side 
in the binary representation of the number.
Note: If there is no set bit in the integer N, then return 0 from the function.  

Example 1:
Input: N = 18
Output: 2
Explanation: Binary representation of 18 is 010010,the first set bit from the right side is at position 2.

Example 2:
Input: N = 12 
Output: 3 
Explanation: Binary representation of  12 is 1100, the first set bit from the right side is at position 3. */

class Solution
{
    public:
    unsigned int getFirstSetBit(int n)
    {
    	//cout<< bitset<8>(n & -n); //rmsbm
        return log2(n & -n) + 1;
    }
};