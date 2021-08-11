/*Given a string s and a dictionary of strings wordDict, return true 
if s can be segmented into a space-separated sequence of one or more dictionary words.

Note that the same word in the dictionary may be reused multiple times in the segmentation.
All the strings of wordDict are unique.

Input: s = "leetcode", wordDict = ["leet","code"]
Output: true
Explanation: Return true because "leetcode" can be segmented as "leet code".

Input: s = "applepenapple", wordDict = ["apple","pen"]
Output: true
Explanation: Return true because "applepenapple" can be segmented as "apple pen apple"  */

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) 
    {
        int n = s.size();
        bool dp[n+1];
        dp[0] = true;
        
        //dp[i] = if s[0 1....i-1] of length i can be segmented or not
        //initially all false
        for(int i=1; i<=n; i++)
        {
            for(int len=1; len<=i; len++) //substring length
            {
                dp[i] = find(wordDict.begin(), wordDict.end(), s.substr(i-len, len)) != wordDict.end() 
                        && dp[i-len];
                if(dp[i] == true)
                    break;
            }
        }
        
        return dp[n];
    }
};

/*
https://practice.geeksforgeeks.org/problems/word-break1352/1
https://practice.geeksforgeeks.org/problems/d857113143f69fab217cf5dab978535542f3cbb1/0/
https://practice.geeksforgeeks.org/problems/word-break-part-23249/1
*/