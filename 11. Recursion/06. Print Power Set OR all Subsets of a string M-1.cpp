class Solution
{
    public:
        vector<string> getSubSequences(string s) //2ⁿ subsets/subsequences
        {
            if(s == "")
                return {""};  // Φ   (since 2⁰ = 1)

            char first = s[0]; //a
            string rest = s.substr(1); //bc
            
            vector<string> powerSetOfRestStr = getSubSequences(rest); // {--, b-, -c, bc}
            vector<string> powerSetOfFullStr;
            
            for(string x: powerSetOfRestStr)
            {
                powerSetOfFullStr.push_back("" + x);
                powerSetOfFullStr.push_back(first + x);
            } // {---, -b-, --c, -bc,     a--, ab-, a-c, abc}
            
            return powerSetOfFullStr;
        }
        vector<string> AllPossibleStrings(string s) 
        {
            vector<string> ps = getSubSequences(s);
            
            sort(ps.begin(), ps.end()); //sort the o/p vector if asked in lexicographically-sorted order
            ps.erase(ps.begin()); //asked for non-empty subsets (2ⁿ-1)
            return ps;
        }
};