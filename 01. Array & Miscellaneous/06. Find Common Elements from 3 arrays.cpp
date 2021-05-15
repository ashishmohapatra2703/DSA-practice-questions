#include <iostream>
#include <vector>
#include <map>
using namespace std;

vector<long long> GetCommonElementsfrom3arrays(vector<long long> arr1, vector<long long> arr2, vector<long long> arr3) 
{
    vector<long long> common;
    map<long long, int> mp;
    
    for(long long i=0; i<arr1.size(); i++)
    {
        if(mp[arr1[i]] == 0)
            mp[arr1[i]] = 1;
    }
    for(long long i=0; i<arr2.size(); i++)
    {
        if(mp[arr2[i]] == 1)
            mp[arr2[i]] = 2;
    }
    for(long long i=0; i<arr3.size(); i++)
    {
        if(mp[arr3[i]] == 2)
            mp[arr3[i]] = 3;
    }
    
    for(auto it=mp.begin(); it!=mp.end(); it++) 
    {
        if(it->second == 3)
            common.push_back(it->first);
    }
    return common;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long a;
        cin>>a;
        long long b;
        cin>>b;
        long long c;
        cin>>c;
        
        vector<long long> arr1(a);
        for (long long i=0; i<a; i++) 
            cin>>arr1[i];
        
        vector<long long> arr2(b);
        for (long long i=0; i<b; i++) 
            cin>>arr2[i];

        vector<long long> arr3(c);
        for (long long i=0; i<c; i++) 
            cin>>arr3[i];

        vector<long long> result = GetCommonElementsfrom3arrays(arr1, arr2, arr3);
        if(result.size()==0)
        {
            cout<<"-1";
        }
        else
        {
            for(long long i=0; i<result.size(); i++)
                cout<<result[i]<<" ";
        }
        cout<<endl;
    }
}

/*
i/p --
a=6  arr1= 1 5 10 20 40 80
b=5  arr2= 6 10 20 80 100
c=8  arr3= 3 4 15 20 30 70 80 120

map-
1->1   5->1   10->1   20->1   40->1   80->1
1->1   5->1   6->0   10->2   20->2   40->1   80->2   100->0 
1->1   3->0   4->0   5->1   6->0   10->2   15->0   20->3   30->0   40->1   70->0   80->3   100->0   120->0 

o/p: common = 20 80
*/