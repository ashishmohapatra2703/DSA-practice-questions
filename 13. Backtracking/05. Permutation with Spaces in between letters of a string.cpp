/* Given a string you need to print all possible strings that can be made by placing spaces (zero or one) 
in between them. The output should be printed in sorted increasing order of strings

Input: S = "ABC"
Output: (A B C)(A BC)(AB C)(ABC)  */

class Solution{
public:
    void PermutationWithSpaces(string &str, int &start, int &end, vector<string> &allPerms)
    {
        if(start == end)
        {
            allPerms.push_back(str);
            return;
        }
        
        str.insert(start+1, " ");  //insert(size_type idx, const string& str)
        start+=2;
        end++;
        PermutationWithSpaces(str, start, end, allPerms);
        start-=2;
        end--;
        str.erase(start+1, 1);  //erase (size_type idx, size_type len)
        
        start++;
        PermutationWithSpaces(str, start, end, allPerms);
        start--;
    }
    vector<string> permutation(string S)
    {
        int startIndex = 0;
        int endIndex = S.size()-1;
        
        vector<string> ans;
        PermutationWithSpaces(S, startIndex, endIndex, ans);
        return ans;
    }
};