/*Given an array A of n positive numbers. The task is to find the first Equilibium Point in the array. 
Equilibrium Point in an array is a position such that 
the sum of elements before it is equal to the sum of elements after it.

Input: n = 1
A[] = {1}
Output: 1
Explanation: Since its the only element hence its the only equilibrium point. 

Input: n = 5
A[] = {1,3,5,2,2}
Output: 3
Explanation: For second test case equilibrium point is at position 3 as 
elements before it (1+3) = elements after it (2+2).			*/

//M-1 
class Solution {
public:
    // Function to find equilibrium point in the array.
    // a: input array
    // n: size of array
    int equilibriumPoint(long long a[], int n) 
    {
        if(n == 1)
            return 1;
            
        long long prefixSumArr[n];
        prefixSumArr[0] = a[0];
        for(int i=1; i<=n-1; i++)
            prefixSumArr[i] = prefixSumArr[i-1] + a[i];
     
        long long suffixSumArr[n];
        suffixSumArr[n-1] = a[n-1];
        for(int j=n-2; j>=0; j--)
            suffixSumArr[j] = suffixSumArr[j+1] + a[j];
     
    //considering ith index => partition array into two non-empty subarrays in each case
        for(int i=1; i<=n-2; i++)
        {
            if(prefixSumArr[i] == suffixSumArr[i])
            {
                return i+1; //1-based indexing
            }
        }
        return -1;
    }
};

//M-2 optimal
class Solution {
public:
    int equilibriumPoint(long long a[], int n) 
    {
        if(n == 1)
            return 1;
        
        long long totalSum = 0;
        for(int i=0; i<n; i++)
            totalSum += a[i];
            
        long long prefixSum = 0;
        long long suffixSum = 0;
        for(int i=0; i<n; i++)
        {
            prefixSum += a[i];
            suffixSum = totalSum + a[i] - prefixSum;
            
            if(prefixSum == suffixSum)
                return i+1;
        }
        return -1;
    }
};