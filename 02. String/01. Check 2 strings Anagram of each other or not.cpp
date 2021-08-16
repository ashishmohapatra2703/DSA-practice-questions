/*Given two strings a and b consisting of lowercase characters. The task is to 
check whether two given strings are an anagram of each other or not. 
An anagram of a string is another string that contains the same characters, 
only the order of characters can be different. 

Input:  a = geeksforgeeks, b = forgeeksgeeks
Output: YES
Explanation: Both the string have same characters with same frequency. So, both are anagrams.

Time Complexity: O(|a|+|b|).
Auxiliary Space: O(Number of distinct characters).*/

class Solution{
public:
    //Function is to check whether two strings are anagram of each other or not.
    bool isAnagram(string a, string b)
    {
        unordered_map<int, int> mp;
        
        for(int i=0; a[i]!='\0'; i++)
            mp[a[i]-'a']++;
        
        for(int i=0; b[i]!='\0'; i++)
        {
            mp[b[i]-'a']--;
            if(mp[b[i]-'a'] < 0)
                return false;
        }
        return true;
    }
};