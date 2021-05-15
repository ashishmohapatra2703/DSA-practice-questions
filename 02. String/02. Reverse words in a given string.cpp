//Inpuy:  i.like.this.program.very.much
//Output: much.very.program.this.like.i

class Solution{
  public:
    string reverseWords(string S) 
    { 
        string reverseWordsString;
        string word;
        for(int i=S.size()-1; i>=0; i--)
        {
            if(S[i] != '.')
            {
                word += S[i];
            }
            else if(S[i] == '.')
            {
                reverse(word.begin(), word.end());
                reverseWordsString += word + '.';
                word = "";
            }
            if(i==0)
            {
                reverse(word.begin(), word.end());
                reverseWordsString += word;
            }
        }
        return reverseWordsString;
    } 
};