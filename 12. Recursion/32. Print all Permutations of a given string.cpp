#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Permutation(string op, string ip, vector<string> &allPerms)
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
        //ipGone.erase(ipGone.begin()+i);  //<- OR use this
        
        Permutation(opChoice, ipGone, allPerms);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin>>S;
        
        string op = "";
        string ip = S;
        vector<string> ans;
        Permutation(op, ip, ans);
        
        sort(ans.begin(), ans.end()); //all permutations in lexicographically increasing order
        for(string x : ans)
            cout<<x<<" ";
        cout<<endl;
    }
}