#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
using namespace std;

vector<string> PowerSet(string op , string ip)
{
    static vector<string> ps;
    if(ip == "")  //base condition (in recursive tree)
    {
        ps.push_back(op);
        return ps;
    }
    
    string op1 = op;
    string op2 = op + ip[0];
    
    ip.erase(ip.begin()+0);
    
    PowerSet(op1 , ip);
    PowerSet(op2 , ip);
    
    return ps;
}
int main() 
{
    string ip;
    cin>>ip;
    string op = ""; //initialization 
    
    vector<string> allsubsets = PowerSet(op , ip);
    
    map<string, int> mp; //using map to store in lexicographically-sorted order
    for(auto x: allsubsets)
    {
        mp[x]++;
    }
    
    vector<string> DistinctSubsets;
    for(auto it=mp.begin(); it!=mp.end(); it++) 
    {
        if(it->second >= 1) 
            DistinctSubsets.push_back(it->first);
    }
    for(auto x : DistinctSubsets)
        cout<< x <<endl;

    /*OR 
    set<string> DistinctSubsets;
    for(string x: allsubsets)
    {
        if(DistinctSubsets.find(x) == DistinctSubsets.end()) 
        {
            DistinctSubsets.insert(x);
        }
    }
    for(auto it=DistinctSubsets.begin(); it!=DistinctSubsets.end(); it++)
    {
        cout<<(*it)<<endl;
    }
    */
}
/*
i/p :  aab
o/p :
        Φ         Φ (in lexicographically-sorted order)
        b         a
        a         aa
        ab        ab
        aa        aab
        aab       b
*/