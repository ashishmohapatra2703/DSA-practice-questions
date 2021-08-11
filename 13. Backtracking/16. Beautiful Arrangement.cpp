/*Suppose you have n integers labeled 1 through n. A permutation of those n integers perm (1-indexed) 
is considered a beautiful arrangement if for every i (1 <= i <= n), either of the following is true:
    •  perm[i] is divisible by i.
    •  i is divisible by perm[i].
Given an integer n, return the number of the beautiful arrangements that you can construct.

Input: n = 2
Output: 2
Explanation: 
The first beautiful arrangement is [1,2]:
    - perm[1] = 1 is divisible by i = 1
    - perm[2] = 2 is divisible by i = 2
The second beautiful arrangement is [2,1]:
    - perm[1] = 2 is divisible by i = 1
    - i = 2 is divisible by perm[2] = 1     */

class Solution {
public:
    bool isBeautifulToPlace(int &num, int &idx, vector<bool> &taken)
    {
        if(! taken[num] and (num%idx==0 or idx%num==0))
            return true;
        return false;
    }
    void beautifulArrangement(int currIdx, int &N, vector<bool> &taken, int &ways)
    {
        if(currIdx == N+1)
        {
            ways++;
            return;
        }
        
        for(int choice=1; choice<=N; choice++) //at currIdx, choosing numbers 1/2/3.../N
        {
            if(isBeautifulToPlace(choice, currIdx, taken))
            {
                taken[choice] = true;
                beautifulArrangement(currIdx+1, N, taken, ways);
                taken[choice] = false; //backtrack
            }
        }
    }

    int countArrangement(int n) 
    {
        int ways = 0;
        vector<bool> taken(n+1, false);
        beautifulArrangement(1, n, taken, ways); //1-based indexing of perm[]
        return ways;
    }
};