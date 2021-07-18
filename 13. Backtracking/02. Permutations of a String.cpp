/*Given a string S. The task is to print all permutations of a given string.

Input: ABC
Output: ABC ACB BAC BCA CAB CBA  */

//M-1
class Solution{
public:
    void Permutation(string &op, string &ip, vector<string> &allPerms)
    {
        if(ip == "")
        {
            allPerms.push_back(op);
            return;
        }
        
        for(int i=0; i<ip.length(); i++)
        {
            string opChoice = op + ip[i];
            string ipGone = ip.substr(0, i) + ip.substr(i+1);
            Permutation(opChoice, ipGone, allPerms);
            ipGone = ip;
            opChoice = op;
        }
    }
	vector<string> find_permutation(string S)
	{
	    string op = "";
        string ip = S;
        
        vector<string> ans;
        Permutation(op, ip, ans);
        sort(ans.begin(), ans.end()); //all permutations in lexicographically increasing order
        return ans;
	}
};

//M-2
class Solution{
public:
    void Permutation(string &op, int &start, int &end, vector<string> &allPerms)
    {
        if(start == end)
        {
            allPerms.push_back(op);
            return;
        }
        
        for(int itr=start; itr<=end; itr++)
        {
            swap(op[start], op[itr]);
            start++;
            Permutation(op, start, end, allPerms); 
            start--;
            swap(op[start], op[itr]);
        }
    }
    vector<string> find_permutation(string S)
    {
        int startIndex = 0;
        int endIndex = S.size()-1;
        vector<string> ans;
        
        Permutation(S, startIndex, endIndex, ans);
        sort(ans.begin(), ans.end()); //all permutations in lexicographically increasing order
        return ans;
    }
};