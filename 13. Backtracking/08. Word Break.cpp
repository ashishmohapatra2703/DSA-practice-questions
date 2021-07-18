/*Given a string A and a dictionary of n words B, 
find out if A can be segmented into a space-separated sequence of dictionary words. 

Input: n = 12  B = { "i", "like", "sam", "sung", "samsung", "mobile","ice","cream", "icecream", "man", "go", "mango" }
A = "ilikesamsung"
Output: 1
Explanation: The string can be segmented as "i like samsung" or "i like sam sung"  

Input: n = 2  B = { "h", "q" }
A = "hhqhq"
Output: 1
Explanation: The string can be segmented as "h h q h q"  */

//T.C = O(2^n)
bool canBreakintoWords(int start, int end, int &n, string &str, vector<string> &dict)
{
    if(start==n && end==n) //str segmented  into a sequence of dictionary words. 
        return true;
    if(start!=n && end==n) //last word not found in dict/ can't break into words
        return false;
        
    if(find(dict.begin(), dict.end(), str.substr(start, end-start+1)) != dict.end()) //// sub-string found
    {
        return canBreakintoWords(end+1, end+1, n, str, dict);//split the sub-string
        return canBreakintoWords(start, end+1, n, str, dict);//not split , move end pointer ahead
    }
    else //// sub-string not found
    {
        return canBreakintoWords(start, end+1, n, str, dict);//not split , move end pointer ahead
    }
}
int wordBreak(string A, vector<string> &B) 
{
    int n = A.size();
    return canBreakintoWords(0, 0, n, A, B);
}