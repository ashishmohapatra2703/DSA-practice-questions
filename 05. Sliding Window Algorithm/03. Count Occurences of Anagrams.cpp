/*Given a word pat and a text txt. Return the count of the occurences of anagrams of the word in the text.

Input:	txt = forxxorfxdofr
		pat = for
Output: 3
Explanation: for, orf and ofr appears
in the txt, hence answer is 3.

input: 	txt = aabaabaa
		pat = aaba
Output: 4
Explanation: aaba is present 4 times
in txt.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(26) or O(256) */

class Solution{
public:
	int search(string pat, string txt) 
	{
	    unordered_map<char,int> mp;
	    int count_anag = 0;
	    int i=0;
	    int j=0;
	    int K = pat.size();
	    
	    for(int i=0; pat[i]!='\0'; i++)
	    {
	        mp[pat[i]] ++;
	    }
	    int num_left = mp.size(); //no. of dintinct letters in pattern
	    
	    while(j < txt.size())
        {
            if( mp.find(txt[j]) != mp.end() )
            {
                mp[txt[j]]--;
                if(mp[txt[j]] == 0)
                    num_left--;
            }
            
            if(j-i+1 < K)
            {
                j++;
            }
            else if(j-i+1 == K)
            {
                if( num_left == 0)
                    count_anag++;
                    
                    
                if( mp.find(txt[i]) != mp.end() )
                {
                    mp[txt[i]]++;
                    if(mp[txt[i]] == 1)
                        num_left++;
                }
                i++;
                j++;
            }
        }
        return count_anag;
	}
};