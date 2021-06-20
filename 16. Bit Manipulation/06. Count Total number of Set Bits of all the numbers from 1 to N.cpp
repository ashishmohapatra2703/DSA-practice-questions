/* You are given a number N. Find the total count of set bits for all numbers from 1 to N(both inclusive).

Input: N = 4
Output: 5
Explanation:
For numbers from 1 to 4.
For 1: 0 0 1 = 1 set bits
For 2: 0 1 0 = 1 set bits
For 3: 0 1 1 = 2 set bits
For 4: 1 0 0 = 1 set bits
Therefore, the total set bits is 5.

Input: N = 17
Output: 35
Explanation: From numbers 1 to 17(both inclusive), the total number of set bits is 35. */


int highestExponentinPowerOf2inRange(int n) 
{
    int p = 0;
    while((1<<p) <= n)
    {
        p++;
    }
    return p-1;
}
int Solution::solve(int A) 
{
    if(A <= 1)
        return A;
    int x = highestExponentinPowerOf2inRange(A); //or use log2(n)
    return ( ((1LL<<(x-1))*x) + (A-(1LL<<x)+1) + solve(A-(1LL<<x)) )%1000000007;
}
//Time Complexity : O(logA)