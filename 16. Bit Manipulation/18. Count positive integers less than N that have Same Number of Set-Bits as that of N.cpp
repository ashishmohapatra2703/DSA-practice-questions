/*  Constraints : 
    1 <= N <= 10^12   

Given a positive integer N, find out how many positive integers strictly less than N 
have the same number of set bits as N.
Input : 8
Output :3
Explanation: 
Binary representation of 8 : 1000, so number of set bits in 8 is 1.
So the integers less than 8 with same number of set bits are : 
4 = 0100,
2 = 0010, 
1 = 0001 */

class Solution{
public:
    long long nCr(int n, int r) //combination of r setbits in n positions
    {
        if(r>n)
            return 0LL;
        if(r==0 || r==n)
            return 1LL; //base condition
            
        long long result = 1LL;
        for(int i=0; i<r; i++)
        {
            result *= (n-i);
            result /= (i+1);
        }
        return result;
    }
 /* nCr = n.(n-1).(n-2).......(n-(r-1))
          -----------------------------
            1.2.3...................r     */
    int countsetBits(long long N) //Brian Kernighan’s Algorithm
    {
        int count = 0;
        while(N != 0)
        {
            long long rmsbm = (N & -N);
            N = N - rmsbm;
            count ++;
        }
        return count;
    }

    long long countNumLessThanNSameSetBitsAsN(long long N, int length, int setBits)
    {
        if(length == 1) //either it be binary 0 or 1 => required ans = 0
            return 0;
            
        int MSBidx = length-1;
        if((N & (1LL<<MSBidx)) == 0) //MSB -> 0
        {
            return countNumLessThanNSameSetBitsAsN(N, length-1, setBits);
        }
        else //MSB -> 1
        {
            long long case1count = countNumLessThanNSameSetBitsAsN(N, length-1, setBits-1);
            long long case2count = nCr(length-1, setBits); //always < N
            return case1count + case2count; 
        }
    }
    long long count(long long x) 
    {
        int setBits = countsetBits(x);
        
        return countNumLessThanNSameSetBitsAsN(x, 64, setBits);
    }
};