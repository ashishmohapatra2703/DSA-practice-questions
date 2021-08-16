/*Given two strings, one is a text string and other is a pattern string. The task is 
to print the indexes of all the occurences of pattern string in the text string.
For printing, Starting Index of a string should be taken as 1.  (assume that n > m)

Input:  S = "batmanandrobinarebat", pat = "bat"
Output: [1, 18]
Explanation: The string "bat" occurs twice in S, 
one starts are index 1 and the other at index 18. */

//M-1 Two Pointers   //O(|txt|*|pat|) in the worst case.
class Solution{
public:
    vector<int> search(string pat, string txt)
    {
        vector<int> occur;
        int K = pat.length();
        int N = txt.length();

        for(int i=0; i<=N-K; i++)
        {
            int j;
            for(j=0; j<=K-1; j++)
            {
                if(txt[i+j] != pat[j])
                    break;
            }
            
            if(j == K) //txt[i, i+1, ...i+K-1] matched with pattern pat[0...K-1]
                occur.push_back(i+1); //1-based indexing in answer
        }
        return occur;
    }
};

//M-2 using sliding wondow    //O(|txt|*|pat|) in the worst case.
class Solution{
public:
    vector<int> search(string pat, string txt)
    {
        vector<int> occur;
        int K = pat.length();
        int N = txt.length();

        int i=0;
        int j=0;
        string patMatch;
        while(j < N)
        {
            patMatch += txt[j];
            
            if(j-i+1 < K)
            {
                j++;
            }
            else if(j-i+1 == K)
            {
                if(txt[i]==pat[0] and patMatch == pat)  //here patMatch is basically = txt.substr(i, K)
                    occur.push_back(i+1); //1-based indexing in answer

                patMatch.erase(patMatch.begin() + 0); //txt[i] popped from front of patMatch
                i++;
                j++;
            }
        }
        return occur;
    }
};

//M-3 KMP Pattern Searching Algo.  //O(|txt|) in the worst case.