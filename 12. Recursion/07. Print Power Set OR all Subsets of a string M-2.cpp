#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    public:
        vector<string> ps;
        void PowerSet(string op , string ip)
        {
            if(ip == "")  //base condition (in recursive tree)
            {
                if(op != "") //if empty subset is to be discarded
                    ps.push_back(op);
                return;
            }
                    
            string op1 = op;
            string op2 = op + ip[0];
                    
            ip.erase(ip.begin()+0);
                    
            PowerSet(op1 , ip);
            PowerSet(op2 , ip);
        }
        vector<string> AllPossibleStrings(string s) 
        {
            string ip = s;
            string op = "";

            PowerSet(op , ip);
            
            sort(ps.begin() , ps.end()); //sort the o/p vector if asked in lexicographically-sorted order
            return ps;
        }
};

int main()
{
    int tc;
    cin >> tc;
    while(tc--)
    {
        string s;
        cin >> s;
        
        Solution ob;
        vector<string> res = ob.AllPossibleStrings(s); //all 2^n subsequences or subsets (n = string length)
        
        for(auto i: res)
            cout << i <<" ";
        cout<<endl;
    }
} 
/*
i/p :  aab
o/p :
        Φ           Φ  (in lexicographically-sorted order)
        b           a
        a           a
        ab          aa
        a           aab
        ab          ab
        aa          ab
        aab         b
*/