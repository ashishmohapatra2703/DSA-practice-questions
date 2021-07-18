/*Given an array nums of distinct integers, that might contain duplicates,
return all the possible permutations. You can return the answer in any order.

Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]   

Input: nums = [1,1,2]
Output: [[1,1,2], [1,2,1], [2,1,1]]    */

//less time & memory usage, using parameters as pass by reference and backtracking its values
class Solution {
public:
    void Permutation(vector<int> &op, vector<int> &ip, set<vector<int>> &allPerms)
    {
        if(ip.size() == 0)
        {
            allPerms.insert(op);
            return;
        }
        
        for(int i=0; i<ip.size(); i++)
        {
            op.push_back(ip[i]); //opChoice
            int temp = ip[i];
            ip.erase(ip.begin()+i); //ipGone
            
            Permutation(op, ip, allPerms);
            
            ip.insert(ip.begin()+i, temp); //undo
            op.pop_back(); //undo
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<int> op;
        vector<int> ip = nums;
        set<vector<int>> DistinctPermutations; //set will sort lexicographically the DistinctPermutations
        
        Permutation(op, ip, DistinctPermutations);
        
        vector<vector<int>> ans;
        for(auto x: DistinctPermutations)
            ans.push_back(x);
        return ans;
    }
};