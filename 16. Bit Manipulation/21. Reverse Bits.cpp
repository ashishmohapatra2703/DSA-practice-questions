/*Given a non-negative integer n. Reverse the bits of n and print the number obtained after reversing the bits.
Note:  The actual binary representation of the number is being considered for reversing the bits, 
no leading 0’s are being considered.

Input : 
N = 11
Output:
13
Explanation:
(11)10 = (1011)2.
After reversing the bits we get: (1101)2 = (13)10.   */

class Solution
{
    public:
    int reverse(int n, int i) 
    {
        //ith idx = index of 1st set bit of n, goes till 0th
        //j starts from 0th to length of actual binary number representation 
        int reversenum = 0;
        int j = 0;
        for(   ;  i>=0;  i--,j++)
        {
            //ith Bit of Num to be copied to jth Bit of reversenum
            if( (n & (1<<i)) != 0 )
                reversenum |= (1<<j); 
            //if ith Bit of Num is 1 => then jth bit of reversenum is to be set
            //else ith Bit of Num is 0 => then jth bit of reversenum is unset / left as it is 
        }
        return reversenum;
    }
    
    unsigned int reverseBits(unsigned int n)
    {
        for(int i=31; i>=0; i--)
        {
            if( (n & (1<<i)) != 0 ) //got the 1st Set-Bit
                return reverse(n, i); 
        }
    }
};