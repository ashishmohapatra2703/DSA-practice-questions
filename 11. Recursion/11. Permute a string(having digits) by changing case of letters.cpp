class Solution 
{
public:
    void PermuteCase(string op, string ip, vector<string> &perm)
    {
        if(ip == "")
        {
            perm.push_back(op);
            return;
        }
        
        if(isalpha(ip[0])) //if alphabet
        {
            string op1 = op;
            op1.push_back(tolower(ip[0]));
            string op2 = op;
            op2.push_back(toupper(ip[0]));

            ip.erase(ip.begin()+0);

            PermuteCase(op1 , ip, perm);
            PermuteCase(op2 , ip, perm);
        }
        else // if digit
        {
            string op1 = op;
            op1.push_back(ip[0]);
            
            ip.erase(ip.begin()+0);
            
            PermuteCase(op1 , ip, perm);
        }
    }
    vector<string> letterCasePermutation(string S) 
    {
        string ip = S;
        string op = "";
        
        vector<string> result;
        PermuteCase(op , ip, result);
        
        return result;
    }
};