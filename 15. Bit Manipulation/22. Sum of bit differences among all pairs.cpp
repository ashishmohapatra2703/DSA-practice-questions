/*We define f (X, Y) as number of different corresponding bits in binary representation of X and Y. 
For example, f (2, 7) = 2, since binary representation of 2 and 7 are 010 and 111, respectively. 
The first and the third bit differ, so f (2, 7) = 2.

You are given an array A of N integers, A1, A2 ,…, AN. 
Find sum of f(Ai, Aj) for all pairs (i, j) such that 1 ≤ i, j ≤ N. Return the answer modulo 10^9+7.

Input: N = 3
A = {1, 3, 5}  => {001, 011, 101}
Output: 8
Explaination: We return 
f(1, 1) + f(1, 3) + f(1, 5) + 
f(3, 1) + f(3, 3) + f(3, 5) + 
f(5, 1) + f(5, 3) + f(5, 5) =   0 + 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0 = 8  */

//M-1 Time Complexity : 0(N²) TLE
class Solution{
public:
    int mod = 1e9+7;
    int countsetBits(long long int n) 
    {
        int count = 0;
        while(n != 0)
        {
            long long int rmsbm = (n & -n);
            n = n - rmsbm;
            count ++;
        }
        return count;
    }
    int countBits(int N, long long int A[])
    {
        int sumOfBitDiffAmongAllPairs = 0;
        for(int i=0; i<N; i++)
        {
            for(int j=0; j<N; j++)
            {
                long long int XORofPair = A[i] ^ A[j];
                sumOfBitDiffAmongAllPairs += countsetBits(XORofPair);
            }
        }
        return sumOfBitDiffAmongAllPairs%mod;
    }
};


//M-2 Time Complexity : 0(32.N) optimal
class Solution{
public:
    int mod = 1e9+7;
    int countBits(int N, long long int A[])
    {
        int sumOfBitDiffAmongAllPairs = 0;
        for(int i=0; i<32; i++)
        {
            int numbers_ithBit_1 = 0;
            int numbers_ithBit_0 = 0;
            
            for(int j=0; j<N; j++)
            {
                if( (A[j] & (1<<i)) == 0 )
                    numbers_ithBit_0++;
                else
                    numbers_ithBit_1++;
            }
            sumOfBitDiffAmongAllPairs += numbers_ithBit_1*numbers_ithBit_0*2; 
            //possible combinations of numbers contributing to BitDiff in ith index
            //(*2 for taking pair reversed into account ) 
        }
        return sumOfBitDiffAmongAllPairs%mod;
    }
};