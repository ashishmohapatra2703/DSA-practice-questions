/*Given a string A and a dictionary of n words B, 
find out if A can be segmented into a space-separated sequence of dictionary words. 

Input: n = 12  B = { "i", "like", "sam", "sung", "samsung", "mobile","ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as "i like samsung" or "i like sam sung"  

Input: n = 2  B = { "h", "q" }
A = "hhqhq"
Output: 1
Explanation: The string can be segmented as "h h q h q" 

Note that the same word in the dictionary may be reused multiple times in the segmentation. */


//T.C = O(2^n)
class Solution{
public:
    void canBreakintoWords(int start, int end, int &n, 
                           string &str, vector<string> &dict, bool &canBreak)
    {
        if(start==n && end==n) //str segmented into a sequence of dictionary words. 
        {
            canBreak = true;
            return;
        }
        if(start!=n && end==n) //last word not found in dict/ can't break into words
            return;
            
           
        if(find(dict.begin(), dict.end(), str.substr(start, end-start+1)) != dict.end()) //// sub-string found
        {
            canBreakintoWords(end+1, end+1, n, str, dict, canBreak);//split the sub-string
            canBreakintoWords(start, end+1, n, str, dict, canBreak);//not split , move end pointer ahead
        }
        else //// sub-string not found
        {
            canBreakintoWords(start, end+1, n, str, dict, canBreak);//not split , move end pointer ahead
        }
    }
    // A : given string to search
    // B : vector of available strings
    int wordBreak(string A, vector<string> &B) 
    {
        int n = A.size();
        bool canBreak = false;
        canBreakintoWords(0, 0, n, A, B, canBreak);
        return canBreak;
    }
};

//see DP method for optimised approach O(n²)