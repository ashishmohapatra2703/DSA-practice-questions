/*Given an array of N integers and Q queries, each query having a range 
from index L to R. Find the maximum prefix-sum for the range L to R.
NOTE: Assume 0 based indexing.

Input: a[] = {-1, 2, 3, -5} 
Q = 2
L1 = 0, R1 = 3
L2 = 1, R2 = 3
Output:
4 5
Explanation:
The range (0, 3) in the 1st query is {-1, 2, 3, -5}, 
hence, the max prefix-sum will be -1 + 2 + 3 = 4. 
The range (1, 3) in the 2nd query is {2, 3, -5}, 
hence, the max prefix-sum will be 2 + 3 = 5.

Time Complexity: O(N*Q)
Auxiliary Space: O(1) 		*/

class Solution{
  public:
    vector<int> maxPrefixes(int a[], int L[], int R[], int N, int Q) 
    {
        vector<int> rangeMaxPSum;
        for(int q=0; q<Q; q++)
        {
            int maxPSum = INT_MIN;
            int PSum = 0;
            for(int i=L[q]; i<=R[q]; i++)
            {
                PSum += a[i];
                maxPSum = max(maxPSum, PSum);
            }
            rangeMaxPSum.push_back(maxPSum);
        }
        return rangeMaxPSum;
    }
};