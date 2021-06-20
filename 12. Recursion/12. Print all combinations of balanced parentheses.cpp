class Solution 
{
public:
    void BalanceParenthesis(string op, int open, int close, vector<string> &bp)
    {
        if(open==0 && close==0)
        {
            bp.push_back(op);
            return;
        }
        
        if(open != 0)
        {
            string op1 = op + "(";
            BalanceParenthesis(op1, open-1, close, bp);
        }
        if(close > open)
        {
            string op2 = op + ")";
            BalanceParenthesis(op2, open, close-1, bp);
        }
    }
    vector<string> generateParenthesis(int n) 
    {
        int open = n;
        int close = n;
        
        string op = "";
        
        vector<string> bp;
        BalanceParenthesis(op, open, close, bp);
        return bp;
    }
};
/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/