/*Given an array arr[] of integers of size N that might contain duplicates, 
the task is to find all possible unique subsets in lexographical order. 
Note: Each subset should be sorted.

Input: N = 3, arr[] = {2,1,2}
Output:(),(1),(1 2),(1 2 2),(2),(2 2)
Explanation: 
All possible subsets = (),(2),(1),(1,2),(2),(2,2),(2,1),(2,1,2)
After Sorting each subset = (),(2),(1),(1,2),(2),(2,2),(1,2),(1,2,2) 
Unique Susbsets in Lexicographical order = (),(1),(1,2),(1,2,2),(2),(2,2)

Input: N = 4, arr[] = {1,2,3,3}
Output: (),(1),(1 2),(1 2 3),(1 2 3 3),(1 3),(1 3 3),(2),(2 3),(2 3 3),(3),(3 3)

Expected Time Complexity: O(2^N).
Expected Auxiliary Space: O(2^N * X), X = Length of each subset.*/

//optimized recursive solution using backtracking
class Solution{
public:
    void PowerSet(vector<int> &ip, int ipItr, int &n, 
                    vector<int> &op, vector<vector<int>> &ps)
    {
        if(ipItr == n)  //base condition
        {
            ps.push_back(op);
            return;
        }

        PowerSet(ip, ipItr+1, n, op, ps);

        op.push_back(ip[ipItr]);
        PowerSet(ip, ipItr+1, n, op, ps);
        op.pop_back();
    }
    
    //Function to find all possible unique subsets.
    vector<vector<int> > AllSubsets(vector<int> arr, int n)
    {
        vector<int> ip = arr;
        int size = arr.size();
        vector<int> subset;
        
        vector<vector<int>> allsubsets;
        PowerSet(ip, 0, size, subset, allsubsets);
        
        //////////////// To handle duplicate subsets ///////////////////////
        set<vector<int>> DistinctSubsets;
        for(vector<int> x: allsubsets)
        {
            sort(x.begin() , x.end()); //Elements in each subset must be in increasing order.
            DistinctSubsets.insert(x); //set will sort lexicographically the DistinctSubsets
        }

        vector<vector<int>> DistinctSubsetsAns;
        for(auto it=DistinctSubsets.begin(); it!=DistinctSubsets.end(); it++)
        {
            DistinctSubsetsAns.push_back(*it);
        }
        return DistinctSubsetsAns;
        ///////////////////////////////////////////////////////////////////
    }
};