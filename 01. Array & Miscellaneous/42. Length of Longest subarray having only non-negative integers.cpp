/*Given an array A[] of size N,
return length of the longest subarray of non- negative integers.
Note: Subarray here means a continuous part of the array.

Input : N = 9 A[] = {2, 3, 4, -1, -2, 1, 5, 6, 3}
Output : 4
Explanation : The subarray [1, 5, 6, 3] has longest length 4 and contains no negative integers
 
Input : N = 10 A[] = {1, 0, 0, 1, -1, -1, 0, 0, 1, 0}
Output : 4
Explanation : Subarrays [1, 0, 0, 1] and [0, 0, 1, 0] have equal lengths 
but sum of first one is greater so that will be the output. */

//Two Pointers Approach
long long int longestSubarry(long long int A[], long long int N) 
{
    long long start = 0;
    long long end = 0;
    long long maxPostiveWindow = 0;
    
    while(end < N)
    {
        if(A[end] < 0)
        {
            start = end+1;
            end++;
        }
        else if(A[end] >= 0)
        {
            maxPostiveWindow = max(maxPostiveWindow, end-start+1);
            end++;
        }
    }
    return maxPostiveWindow;
}