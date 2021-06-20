/* Given a non-empty array of integers, return the k most frequent elements. (leetcode) 
    Input: nums = [1,1,1,2,2,3], k = 2
    Output: [1,2]   
  t.c = O(n logk)         */
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) 
    {
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++)
        {
            mp[nums[i]] ++;
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minh; //MIN-HEAP
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            minh.push({it->second , it->first});
            
            if(minh.size() > k)
                minh.pop();
        }
        
        vector<int> topKfrqele;
        while(! minh.empty())
        {
            topKfrqele.push_back(minh.top().second);
            minh.pop();
        }
        return topKfrqele;
    }   
};