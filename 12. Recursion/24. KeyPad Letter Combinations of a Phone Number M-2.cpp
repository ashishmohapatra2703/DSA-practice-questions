class Solution {
public:
    vector<string> codes = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    void keyPadCombinations(string op, string ip, vector<string> &letterComb)
    {
        if(ip == "")
        {
            if(op != "") 
                letterComb.push_back(op);
            return;
        }
        
        string opChoices = codes[ip[0]-48]; 
        ip.erase(ip.begin()+0);
        
        for(char x: opChoices)
        {
            string opChoice = op + x;
            keyPadCombinations(opChoice , ip, letterComb);
        }
    }

    vector<string> letterCombinations(string digits) 
    {
        string ip = digits; 
        string op = ""; 
        
        vector<string> result;
        keyPadCombinations(op, ip, result);
        return result;
    }
};