/*  https://leetcode.com/problems/find-k-closest-elements/
    https://practice.geeksforgeeks.org/problems/k-closest-elements3619/1 //NOT passed
Given a array arr, two integers k and x, 
find the k closest elements to x in the array. The result should also be sorted in ascending order. 
If there is a tie, the smaller elements are always preferred.
Example 1:
    Input: arr = [1,2,3,4,5], k = 4, x = 3
    Output: [1,2,3,4]
Example 2:
    Input: arr = [1,2,3,4,5], k = 4, x = -1
    Output: [1,2,3,4]                */
class Solution 
{
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) 
    {
        priority_queue<pair<int,int>> maxh; //MAX-HEAP
    	for(int i=0; i<arr.size(); i++)
    	{
    	    maxh.push({abs(arr[i]-x) , arr[i]});
    	        
            if(maxh.size() > k)
                maxh.pop();
    	}
    	    
    	vector<int> kthClosest;
    	while(! maxh.empty())
    	{
            kthClosest.push_back(maxh.top().second);
    	    maxh.pop();  
    	}
    	sort(kthClosest.begin() , kthClosest.end());
    	return kthClosest;
    }
};