/*Given an array containing N integers (having **both positive and negative integers**) 
and a positive integer K, find the length of the longest sub array 
with sum of the elements divisible by the given value K.

Input: A[] = {2, 7, 6, 1, 4, 5}  K = 3
Output: 4
Explanation:The subarray is {7, 6, 1, 4} with sum 18, which is divisible by 3.

Input: A[] = {-2, 2, -5, 12, -11, -1, 7}  K = 3
Output: 5
Explanation: The subarray is {2,-5,12,-11,-1} with sum -3, which is divisible by 3.
 
Time Complexity: O(N)
Auxiliary Space: O(N) 	*/
class Solution{
public:	
	int longSubarrWthSumDivByK(int arr[], int n, int k)
	{
	    unordered_map<int,int> pSumModKIdx;
	    int window = 0; //window size of subArr sum % K = 0
	    int pSum = 0; 
        int pSumModK;
        
        for(int i=0; i<n; i++)
        {
            pSum += arr[i];
            pSumModK = (pSum%k<0) ? pSum%k+k : pSum%k;
            
            if(pSumModK == 0)
                window = max(window, i-(0)+1);
            if(pSumModKIdx.find(pSumModK) != pSumModKIdx.end())
                window = max(window, i-(pSumModKIdx[pSumModK]+1)+1);
            
            if(pSumModKIdx.find(pSumModK) == pSumModKIdx.end()) //updation only for pSumModK first occurrence 
                pSumModKIdx[pSumModK] = i;
        }
        return window;
	}
};