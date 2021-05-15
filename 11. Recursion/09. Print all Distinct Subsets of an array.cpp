/*
Input:
2
3
1 2 2
4
1 2 3 3

Output:
()(1)(1 2)(1 2 2)(2)(2 2)
()(1)(1 2)(1 2 3)(1 2 3 3)(1 3)(1 3 3)(2)(2 3)(2 3 3)(3)(3 3) 
*/
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

void PowerSet(vector<int> op, vector<int> ip, vector<vector<int>> &ps)
{
    if(ip.size()==0)  //base condition (in recursive tree)
    {
        ps.push_back(op);
        return;
    }
    
    vector<int> op1 = op;
    vector<int> op2 = op;
    op2.push_back(ip[0]);
    
    ip.erase(ip.begin()+0);
    
    PowerSet(op1 , ip , ps);
    PowerSet(op2 , ip , ps);
}

int main() 
{
    int tc;
    cin>>tc;
    while(tc--)
    {
        int n;
        cin>>n;
        
        vector<int> ip(n);
        for(int i=0; i<n; i++)
            cin>>ip[i];
        vector<int> op; //initialization 
        
        vector<vector<int>> allsubsets;
        PowerSet(op , ip , allsubsets);
        
        map<vector<int> ,int> mp;
        for(int i=0; i<allsubsets.size(); i++)
        {
            sort(allsubsets[i].begin() , allsubsets[i].end()); //Elements in each subset must be in increasing order.
            
            if(mp[allsubsets[i]] == 0)
                mp[allsubsets[i]] ++;
        }
        vector<vector<int>> DistinctSubsets;
        for(auto it=mp.begin(); it!=mp.end(); it++)//map will sort lexicographically the DistinctSubsets
        {
            if(it->second == 1)
                DistinctSubsets.push_back(it->first);
        }
        
        
        //printing dintinct subsets sorted lexicographically
        for(int i=0; i<DistinctSubsets.size(); i++)
        {
            cout<<"(";
            for(int j=0; j<DistinctSubsets[i].size(); j++)
            {
                cout<<DistinctSubsets[i][j];
                if(j != DistinctSubsets[i].size()-1)
                    cout<<" ";
            }
            cout<<")";
        }
        cout<<endl; 
    }
}