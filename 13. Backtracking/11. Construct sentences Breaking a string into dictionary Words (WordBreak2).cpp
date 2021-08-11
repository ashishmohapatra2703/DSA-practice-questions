/* Given a string s and a dictionary of strings wordDict,
add spaces in s to construct a sentence where each word is a valid dictionary word. 
Return all such possible sentences in any order.
Note that the same word in the dictionary may be reused multiple times in the segmentation.

Input:  s = "catsanddog",  wordDict = ["cat","cats","and","sand","dog"]
Output: ["cats and dog", "cat sand dog"]

Input:  s = "pineapplepenapple",  wordDict = ["apple","pen","applepen","pine","pineapple"]
Output: ["pine apple pen apple", "pineapple pen apple", "pine applepen apple"]
Explanation: Note that you are allowed to reuse a dictionary word.      */


class Solution {
public:
    bool isWordPresentInDictionary(string word, vector<string> dict)
    {
        if(find(dict.begin(), dict.end(), word) != dict.end())
            return true;
        return false;
    }

    void breakintoWords(int start, int end, 
                        int &n, string &str, vector<string> &dict,
                        string segmented, vector<string> &allSegmented)
    {
        if(start==n && end==n) //str segmented  into a sequence of dictionary words. 
        {
            segmented.pop_back(); //to remove last space
            allSegmented.push_back(segmented);
            return;
        }
        if(start!=n && end==n) //last word not found in dict/ can't break into words
            return;
        
        
        string word = str.substr(start, end-start+1);
        if(isWordPresentInDictionary(word, dict)) //// sub-string found
        {
            breakintoWords(end+1, end+1, n, str, dict, segmented+word+" ", allSegmented);//split the sub-string
            
            breakintoWords(start, end+1, n, str, dict, segmented, allSegmented);//not split , move end pointer ahead
        }
        else //// sub-string not found
        {
            breakintoWords(start, end+1, n, str, dict, segmented, allSegmented);//not split , move end pointer ahead
        }
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) 
    {
        vector<string> allSegmented;
        string segmented;
        int len = s.size();
        breakintoWords(0, 0, len, s, wordDict, segmented, allSegmented);
        return allSegmented;
    }
};