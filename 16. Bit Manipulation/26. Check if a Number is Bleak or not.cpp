/*Given an integer, check whether it is Bleak or not.
A number ‘n’ is called Bleak if it cannot be represented as sum of a positive number x and set bit count in x, 
i.e., x + countSetBits(x) is not equal to n for any non-negative number x.

Input: 4
Output: 1
Explanation: There is no any possible x
such that x + countSetbit(x) = 4

Input: 3
Output: 0
Explanation: 3 is not a Bleak number as 
2 + countSetBit(2) = 3.  */

class Solution {
public:
    int countSetBits(int N) 
    {
        int count = 0;
        while(N != 0)
        {
            int rmsbm = (N & -N);
            N = N - rmsbm;
            count ++;
        }
        return count;
    }
    
	int is_bleak(int n)
	{
	    for(int x=1; x<=n; x++)
	    {
	        if(x + countSetBits(x) == n)
	            return false;
	    }
	    return true;
	}
};