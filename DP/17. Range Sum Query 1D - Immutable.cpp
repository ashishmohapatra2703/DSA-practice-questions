/*You are given an array arr[] of n integers and q queries in an array queries[] of length 2*q 
containing l, r pair for all q queries. You need to compute the following sum over q queries.
Array is 1-Indexed.

Input: 
n = 4 arr = {1, 2, 3, 4}
q = 2 queries = {1, 4, 2, 3}
Output: 10 5
Explaination: In the first query we need sum from 1 to 4 which is 1+2+3+4 = 10. 
In the second query we need sum from 2 to 3 which is 2 + 3 = 5.

Time Complexity: O(n+q)
Auxiliary Space: O(n)*/

class Solution{
public:
    int* prefixSum;
    vector<int> querySum(int n, int arr[], int q, int queries[])
    {
        prefixSum = new int[n+1]; //array can be statically created too
        prefixSum[0] = 0;
        for(int i=1; i<=n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        
        vector<int> rangeSum;
        for(int i=0; i<2*q; i+=2)
        {
            int l = queries[i];
            int r = queries[i+1];
            rangeSum.push_back(prefixSum[r] - prefixSum[l-1]);
        }
        return rangeSum;
    }
};




//Similar Question (Mean of range in array)
/* Given an array of n integers and q queries. Write a program to 
find floor value of mean in range l to r for each query in a new line. (0-indexed)*

Input : Arr[] = {1, 2, 3, 4, 5}, Q = 3
queries[] = {0, 2, 1, 3, 0, 4}
Output : 2 3 3
Explanation:
Query 1: L = 0 and R = 2 
=> Sum = 6, Integer Count = 3, So, Mean is 2
Query 2: L = 1 and R = 3
=> Sum = 9, Integer Count = 3, So, Mean is 3
Query 3: L = 0 and R = 4
Sum = 15, Integer Count = 5, So, the Mean is 3.
So, In the end, the function will return the array [2, 3, 3] as an answer.

Time Complexity: O(q + n)
Auxiliary Space: O(n)            */
class Solution{
public:
    vector<int> findMean(int arr[],int queries[],int n,int q)
    {
        int prefixSum[n+1];
        prefixSum[0] = 0;
        for(int i=1; i<=n; i++)
        {
            prefixSum[i] = prefixSum[i-1] + arr[i-1];
        }
        
        vector<int> rangeMean;
        for(int i=0; i<q; i+=2)
        {
            int l = queries[i] + 1; //add 1
            int r = queries[i+1] + 1; //to 1-based indexing (to match with prefixSum[n+1])
            int range = r-l+1;
            rangeMean.push_back((prefixSum[r]-prefixSum[l-1]) / range);
        }
        return rangeMean;
    }
};