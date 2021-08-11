/*Given an integer n, 
return the count of all numbers with unique digits, x, where 0 <= x < 10^n.

Input: n = 2
Output: 91
Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, 
excluding 11,22,33,44,55,66,77,88,99    */

//M-1
class Solution {
private:
    int dp[9];
public:
    Solution()
    {
        dp[0] = 1;
        int idigitdupliNums = 0;
        int idigitUniqueNums = 1; //base case for range= [0]
        
        for(int i=1; i<=8; i++) // [1,9] , [10,99] , [100,999] , [1000,9999] , ....
        {
            int idigitNumsCount = pow(10,i) - pow(10,i-1);
            
            idigitdupliNums = idigitdupliNums*10 + idigitUniqueNums*(i-1);
            idigitUniqueNums = idigitNumsCount - idigitdupliNums;
            dp[i] = idigitUniqueNums;
            
            dp[i] += dp[i-1]; //prefix sum, i.e, count of all <=i digit numbers with unique digits
        }
    }
    
    int countNumbersWithUniqueDigits(int n) 
    {
        return dp[n];
    }
};


//M-2 observing the pattern in no. of N-digit numbers with unique digits
class Solution {
private:
    int dp[9];
public:
    Solution()
    {
        dp[0] = 1;
        dp[1] = 9;
        for(int i=2; i<=8; i++)
        {
            dp[i] = dp[i-1]*(11-i);   
        }
    }
    /* dp[9]= 1, 9, 81, 648, 4536, 27216, 136080, 544320 , 1632960
             ------------------------------------------------------
              0, 1,  2,   3,   4,     5,      6,       7,      8      */
    
    int countNumbersWithUniqueDigits(int n) 
    {
        int prefixSum = 0;
        for(int i=0; i<=n; i++)
            prefixSum += dp[i];     //to count all <=i digit numbers with unique digits
        return prefixSum;
    }
};