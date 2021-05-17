/*Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.

Input: n = 13
Output: [1,10,11,12,13,2,3,4,5,6,7,8,9] */

/*The idea is pretty simple. If we look at the order we can find out 
we just keep adding digit from 0 to 9 to every digit and make it a tree.
Then we visit every node in pre-order. 
       1        2        3    ...              9
      /\        /\       /\                 /  |    \
   10 ...19  20...29  30...39   ....       90..91..  99                   */

class Solution {
public:
    void DFS(int i, vector<int> &lexicalNums, int &n)
    {
        if(i > n)
            return;
        
        lexicalNums.push_back(i);
        for(int j=0; j<=9; j++)
        {
            DFS(10*i+j, lexicalNums, n);
        }
    }
    vector<int> lexicalOrder(int n) 
    {
        vector<int> lexicalNums;
        for(int i=1; i<=9; i++)
        {
            DFS(i, lexicalNums, n);
        }
        return lexicalNums;
    }
};