/*Given a dictionary of words and a pattern. 
Every character in the pattern is uniquely mapped to a character in the dictionary.
Find all such words in the dictionary that match the given pattern. 

Input:
N = 4
dict[] = {abb,abc,xyz,xyy}
pattern  = foo
Output: abb xyy
Explanation: xyy and abb have the same character at index 1 and 2 like the pattern.*/



//we assign different integers to the distinct characters of the word and 
//make a string of integers (hash of the word) according to the occurrence of a particular character in that word 
//and then compare it with the hash of the pattern.
vector<string> findMatchedWords(vector<string> dict, string pattern)
{
    vector<string> matched;
    
    unordered_map<char, int> patternHash;
    string patternHashString;
    int num = 0;
    for(int i=0; i<pattern.size(); i++)
    {
        if(patternHash[pattern[i]] == 0) //character for the first time
            patternHash[pattern[i]] = ++num;
            
        patternHashString.push_back(patternHash[pattern[i]] + 48);
    }
    //foo => patternHashString "122"
    
    for(int s=0; s<dict.size(); s++)
    {
        string word = dict[s];

        unordered_map<char, int> wordHash;
        string wordHashString;
        int num = 0;
        for(int i=0; i<word.size(); i++)
        {
            if(wordHash[word[i]] == 0) //character for the first time
                wordHash[word[i]] = ++num;
            
            wordHashString.push_back(wordHash[word[i]] + 48);
        }
        
        if(patternHashString == wordHashString)
            matched.push_back(word);
    }
    return matched;
}


//Better
vector<string> findMatchedWords(vector<string> dict,string pattern)
{
    vector<string> matched;
    
    unordered_map<char, int> patternHash;
    string patternHashString;
    int num = 0;
    for(int i=0; i<pattern.size(); i++)
    {
        if(patternHash[pattern[i]] == 0) //character for the first time
            patternHash[pattern[i]] = ++num;
            
        patternHashString.push_back(patternHash[pattern[i]] + 48);
    }
    //foo => patternHashString "122"
    
    for(int s=0; s<dict.size(); s++)
    {
        string word = dict[s];
        bool matching = true;
        if(word.size() != pattern.size())
        {
            matching = false;
            continue;
        }

        unordered_map<char, int> wordHash;
        string wordHashString;
        int num = 0;
        for(int i=0; i<word.size(); i++)
        {
            if(wordHash[word[i]] == 0) //character for the first time
                wordHash[word[i]] = ++num;
            
            wordHashString.push_back(wordHash[word[i]] + 48);
            
            if(wordHashString[i] != patternHashString[i])
            {
                matching = false;
                break;
            }
        }
        if(matching == true)
            matched.push_back(word);
    }
    return matched;
}





//same concept , different language of question
//done without use of STL

/*Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible 
for every character of str1 to every character of str2 while preserving the order.
Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

Input:
str1 = aab
str2 = xxy
Output: 1
Explanation: There are two different characters in aab and xxy, i.e a and b with frequency 2and 1 respectively. */

class Solution{
  public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        if(str1.length() != str2.length())
                return false;
                
        int str1Hash[26] = {0};
        string str1HashString;
        int num = 0;
        for(int i=0; i<str1.size(); i++)
        {
            if(str1Hash[str1[i]-'a'] == 0) //character for the first time
                str1Hash[str1[i]-'a'] = ++num;
                
            str1HashString.push_back(str1Hash[str1[i]-'a'] + 48);
        }
        //e.g, str1 bbacbad => str1HashString "1123124"
        
        
        int str2Hash[26] = {0};
        string str2HashString;
        num = 0;
        for(int i=0; i<str2.size(); i++)
        {
            if(str2Hash[str2[i]-'a'] == 0) //character for the first time
                str2Hash[str2[i]-'a'] = ++num;
                
            str2HashString.push_back(str2Hash[str2[i]-'a'] + 48);
        }
         
        bool isIsomorphic = true;     
        for(int i=0; i<str1HashString.size(); i++)
        {
            if(str1HashString[i] != str2HashString[i])
            {
                isIsomorphic = false;
                break;
            }
        }
        return isIsomorphic;
    }
};