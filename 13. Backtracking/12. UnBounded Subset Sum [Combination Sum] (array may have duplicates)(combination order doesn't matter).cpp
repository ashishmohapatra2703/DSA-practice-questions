/*Given an array of integers and a sum B, 
find all unique combinations in the array where the sum = B. 
The same number may be chosen from the array an unlimited number of times to make B.
Note:
    1. All numbers will be positive integers.
    2. Elements in a combination (a1, a2, …, ak) must be in non-descending order. (ie, a1 ≤ a2 ≤ … ≤ ak).
    3. The combinations themselves must be sorted in ascending order.
    4. The combinations set must not contain duplicate combinations.

Input: N = 4  ; arr[] = {7,2,6,5}  ; B = 16
Output:
(2 2 2 2 2 2 2 2)
(2 2 2 2 2 6)
(2 2 2 5 5)
(2 2 5 7)
(2 2 6 6)
(2 7 7)
(5 5 6)     

Input: N = 5  ; arr[] = {8,1,8,6,8}  ; targetSum = 12
Output:
(1 1 1 1 1 1 1 1 1 1 1 1)
(1 1 1 1 1 1 6)
(1 1 1 1 8)
(6 6)       */

class Solution {
  public:
    void unBoundedSubsetSum(int itr, vector<int> &arr, 
                            int &currSum, int &targetSum, 
                            vector<int> &combination, vector<vector<int>> &combinations)
    {
        if(currSum == targetSum)
        {
            combinations.push_back(combination);
            return;
        }
        if(itr==arr.size() or currSum > targetSum)
        {
            return;
        }

        combination.push_back(arr[itr]);
        currSum += arr[itr];
        unBoundedSubsetSum(itr, arr, currSum, targetSum, combination, combinations); //include ith element 
        currSum -= arr[itr];
        combination.pop_back();
        
        unBoundedSubsetSum(itr+1, arr, currSum, targetSum, combination, combinations); //exclude ith element & move
    }
    
    //Function to return a list of indexes denoting the required 
    //combinations whose sum is equal to given number.
    vector<vector<int>> combinationSum(vector<int> &A, int B) 
    {
        //delete duplicates in array/ make array of distinct integers (use hashing)
        //as we can use one no. as many times => so its duplicates in same array create duplicate solutions.

        //Sort the array elements (use map)
        // => both combination and combinations will be in sorted order 
        map<int,int> mp;
        for(int i=0; i<A.size(); i++)
            mp[A[i]] ++;
            
        vector<int> uniqueElementsArr;
        for(auto it=mp.begin(); it!=mp.end(); it++)
        {
            if(it->second >= 1)
                uniqueElementsArr.push_back(it->first);
        }
        
        /* or can use this
        sort( A.begin(), A.end() );
        A.erase( unique( A.begin(), A.end() ), A.end() ); */
        
        vector<int> combination;
        vector<vector<int>> combinations; 
        int sum = 0;
        
        unBoundedSubsetSum(0, uniqueElementsArr, sum, B, combination, combinations);
        return combinations;
    }
};