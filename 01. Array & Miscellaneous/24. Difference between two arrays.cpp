// find numbers which are present in the first array, but not present in the second array.
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<long long> DifferenceofArr1minusArr2(vector<long long> arr1, vector<long long> arr2) 
{
    vector<long long> res;
    unordered_map<int,int> mp;
    for(int i=0; i<arr2.size(); i++) 
    {
       mp[arr2[i]] ++;
    }
    for(int i=0; i<arr1.size(); i++) 
    {
        if(mp[arr1[i]] == 0)
            res.push_back(arr1[i]);
    }
    return res;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n; cin>>n;
        int m; cin>>m;
        vector<long long> arr1(n);
        vector<long long> arr2(m);
        for(int i=0; i<n; i++) 
            cin>>arr1[i];
        for(int i=0; i<m; i++) 
            cin>>arr2[i];
            
        vector<long long> InFirstButNotinSecond = DifferenceofArr1minusArr2(arr1, arr2);
        
        for(int i=0; i<InFirstButNotinSecond.size(); i++) 
            cout<<InFirstButNotinSecond[i]<<" ";
        cout<<endl;
    }
}