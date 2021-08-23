/* Find out the maximum sub-array of non-negative numbers from an array.
The sub-array should be contiguous i.e.,a sub-array created by 
choosing the second and fourth element and skipping the third element is invalid.

Maximum sub-array is defined in terms of the sum of the elements in the sub-array. 
Sub-array A is greater than sub-array B if sum(A) > sum(B).

Example:
A : [1, 2, 5, -7, 2, 3]
The two sub-arrays are [1, 2, 5] [2, 3].
The answer is [1, 2, 5] as its sum is larger than [2, 3]

NOTE 1: If there is a tie, then compare with segment's length and 
        return segment which has maximum length.
NOTE 2: If there is still a tie, then 
        return the segment with minimum starting index.     */

//M-1  Using Two Pointers
class Solution{
public:
	vector<int> findSubarray(int a[], int n) 
	{
	    bool allNegativeArr = true;
	    for(int i=0; i<n; i++)
	    {
	        if(a[i] >= 0)
	        {
	            allNegativeArr = false;
	            break;
	        }
	    }
	    if(allNegativeArr == true)
	        return {-1};
	        
	        
        int start = 0;
        int end = 0;
        long subArrSum = 0;
        
        long maxSubArrSum = INT_MIN;
        int mssStart = 0;
        int mssEnd = 0;
        int maxPostiveWindow = 0;
        
        while(end < n)
        {
            if(a[end] < 0)
            {
                subArrSum = 0;
                start = end+1;
                end++;
            }
            
            else if(a[end] >= 0)
            {
                subArrSum += a[end];
                if(subArrSum > maxSubArrSum)
                {
                    maxSubArrSum = subArrSum;
                    mssStart = start;
                    mssEnd = end;
                    maxPostiveWindow = end-start+1;
                }
                //If there is a tie, then compare with segment's length and
                //return segment which has maximum length.
                else if(subArrSum == maxSubArrSum)
                {
                    if(end-start+1 > maxPostiveWindow)
                    {
                        maxSubArrSum = subArrSum;
                        mssStart = start;
                        mssEnd = end;
                        maxPostiveWindow = end-start+1;
                    }
                    //If there is still a tie, then return the segment
                    //with minimum starting index.
                    else if(end-start+1 == maxPostiveWindow)
                    {
                        if(start < mssStart)
                        {
                            maxSubArrSum = subArrSum;
                            mssStart = start;
                            mssEnd = end;
                            maxPostiveWindow = end-start+1;
                        }
                    }
                }
                end++;
            }
        }
        
        
        vector<int> mxSumPositiveSubArr;
        for(int i=mssStart; i<=mssEnd; i++)
            mxSumPositiveSubArr.push_back(a[i]);

        return mxSumPositiveSubArr;
	}
};