/* Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sum to target.
Note: 
	■ EACH number in candidates may only be USED ONCE in the combination.
	■ The solution set must not contain duplicate combinations.

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[ [1,1,6],
  [1,2,5],
  [1,7],
  [2,6] ] */

//here bounded means 0/1 subset
class Solution {
public:
    void BoundedSubsetSum(int itr, vector<int> &arr, 
                            int &currSum, int &targetSum, 
                            vector<int> &combination, set<vector<int>> &combinations)
    {
        if(currSum == targetSum)
        {
            combinations.insert(combination);
            return;
        }
        if(itr==arr.size() or currSum > targetSum)
        {
            return;
        }

        combination.push_back(arr[itr]);
        currSum += arr[itr];
        BoundedSubsetSum(itr+1, arr, currSum, targetSum, combination, combinations); //include ith element & move
        currSum -= arr[itr];
        combination.pop_back();
        
        BoundedSubsetSum(itr+1, arr, currSum, targetSum, combination, combinations); //exclude ith element & move
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(), candidates.end());
        vector<int> combination;
        set<vector<int>> combinations; //to handle duplicate combinations 
        int sum = 0;
        
        BoundedSubsetSum(0, candidates, sum, target, combination, combinations);
        
        vector<vector<int>> combinationsVec;
        for(auto x: combinations)
            combinationsVec.push_back(x);
        return combinationsVec;
    }
};