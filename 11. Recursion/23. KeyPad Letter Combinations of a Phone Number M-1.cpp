class Solution {
public:
    vector<string> codes = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> keyPadCombinations(string digits)
    {
        if(digits == "")
            return {""};
        
        char first = digits[0]; //4
        string rest = digits.substr(1); //58
        
        vector<string> keyCombinationsRestStr = keyPadCombinations(rest); //{jt, ju, jv, kt, ku, kv, lt, lu, lv}
        vector<string> keyCombinationsOfFullStr;
        
        for(char ch: codes[first-'0'])
        {
            for(string x: keyCombinationsRestStr)
            {
                keyCombinationsOfFullStr.push_back(ch + x);
            }
        } 
        /*  { gjt, gju, gjv, gkt, gku, gkv, glt, glu, glv,
              hjt, hju, hjv, hkt, hku, hkv, hlt, hlu, hlv,
              ijt, iju, ijv, ikt, iku, ikv, ilt, ilu, ilv } */
            
        return keyCombinationsOfFullStr;
    }

    vector<string> letterCombinations(string digits) //458
    {
        if(digits == "")
            return {};  //base case
        return keyPadCombinations(digits);
    }
};


// if i/p digits are given in array format
class Solution{
    public:
    vector<string> codes = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> possibleWords(int a[], int N)
    {
        if(N == 0)
            return {""};
        
        int first = a[0];   //2
        for(int i=1; i<N; i++)
            a[i-1] = a[i];  //rest of array (erasing 0th index element)  //{3, 4}
        
        vector<string> keyCombinationsRestStr = possibleWords(a, N-1); //{dg dh di eg eh ei fg fh fi}
        vector<string> keyCombinationsOfFullStr;
        
        for(char ch: codes[first])
        {
            for(string x: keyCombinationsRestStr)
            {
                keyCombinationsOfFullStr.push_back(ch + x);
            }
        } 
        /*  { adg adh adi aeg aeh aei afg afh afi 
              bdg bdh bdi beg beh bei bfg bfh bfi 
              cdg cdh cdi ceg ceh cei cfg cfh cfi } */
        return keyCombinationsOfFullStr;
    }
};