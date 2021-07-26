/*Given an integer N = the number of pairs of parentheses, 
the task is to generate all combinations of well-formed(balanced) parentheses.

Input: N = 3
Output:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]               */

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution{
public:
    void GenerateBalanceParenthesis(int open, int close, string &BP, vector<string> &allBPs)
    {
        if(open==0 and close==0)
            allBPs.push_back(BP);
            
            
        if(open > 0)
        {
            BP.push_back('(');
            GenerateBalanceParenthesis(open-1, close, BP, allBPs);
            BP.pop_back();
        }
        if(close > open)
        {
            BP.push_back(')');
            GenerateBalanceParenthesis(open, close-1, BP, allBPs);
            BP.pop_back();
        }
    }
    vector<string> AllParenthesis(int n) 
    {
        // int open = n;
        // int close = n;
        string BP;
        vector<string> allBPs;
        
        GenerateBalanceParenthesis(n, n, BP, allBPs);
        return allBPs;
    }
};
