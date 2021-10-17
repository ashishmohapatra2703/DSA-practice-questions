/*Given an integer array and a non-negative integer k, 
count all distinct pairs with difference equal to k, i.e., A[ i ] - A[ j ] = k

Input: array = {1, 5, 4, 1, 2}, k = 0
Output: 1
Explanation: There is only one pair (1, 1) whose difference equal to 0.

Input: array = {1, 5, 3}, k = 2
Output: 2
Explanation: There are two pairs (5, 3) and (1, 3) whose difference equal to 2.*/

class Solution{
public:
	int TotalPairs(vector<int> nums, int k)
	{
	    sort(nums.begin(), nums.end());
	    
        int i = 0;
        int j = 1;
        int n = nums.size();
        set<pair<int,int>> pairsDiffK; //distinct 
        
        while(j<n)
        {
            int pairDiff = nums[j] - nums[i];
            
            if(pairDiff == k)  //pair found is {nums[i] and nums[j]}
            {
                if(i!=j)
                {
                    pairsDiffK.insert({nums[i] , nums[j]});
                    i++;
                    j++;
                }
                else if(i==j and k==0)
                    j++;
            }
            else if(pairDiff > k)
                i++;
            else if(pairDiff < k)
                j++;
        }
        return pairsDiffK.size(); //countPairsDiffK
	}
};