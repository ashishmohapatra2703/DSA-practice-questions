/*Given two strings s and part, perform the following operation on s 
until all occurrences of the substring part are removed:

Find the leftmost occurrence of the substring part and remove it from s.
Return s after removing all occurrences of part.
A substring is a contiguous sequence of characters in a string.

 
Input: s = "axxxxyyyyb", part = "xy"
Output: "ab"
Explanation: The following operations are done:
- s = "axxxxyyyyb", remove "xy" starting at index 4 so s = "axxxyyyb".
- s = "axxxyyyb", remove "xy" starting at index 3 so s = "axxyyb".
- s = "axxyyb", remove "xy" starting at index 2 so s = "axyb".
- s = "axyb", remove "xy" starting at index 1 so s = "ab".
Now s has no occurrences of "xy".*/

class Solution {
public:
    void removeSubstring(string &str, int sItr, string &part, int &partLen)
    {
        if(str == "")
            return;
        if(sItr == str.size())
            return;
        
        if(str[sItr]==part[0] and str.substr(sItr, partLen)==part)
        {
            str = str.substr(0, sItr) + str.substr(sItr+partLen);
            removeSubstring(str, 0, part, partLen);
        }
        else
            removeSubstring(str, sItr+1, part, partLen);
    }
    string removeOccurrences(string s, string part) 
    {
        int k = part.size();
        removeSubstring(s, 0, part, k);
        return s;
    }
};