#include <iostream>
#include <vector>
using namespace std;

//return the arr containing all indices of the key (from idxth index to last idex of given arr)
vector<int> AllIndicesofKey(vector<int> arr, int idx, int key, int foundSoFar)
{
    if(idx == arr.size())
    {
        vector<int> outputArr(foundSoFar , -1); //return arr of length = total no. of occurences of key
        return outputArr;
    }
        
        
    if(arr[idx] == key)
    {
        vector<int> ikeyarr = AllIndicesofKey(arr, idx+1, key, foundSoFar+1);
        ikeyarr[foundSoFar] = idx; //in returning phase of recursion
        return ikeyarr;
    }
    else
    {
        vector<int> ikeyarr = AllIndicesofKey(arr, idx+1, key, foundSoFar);
        return ikeyarr;
    }
}

int main()
{
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++)
        cin>>arr[i];
        
    int key;
    cin>>key;
    
    vector<int> ans = AllIndicesofKey(arr, 0, key, 0);
    for(int i=0; i<ans.size(); i++)
        cout<<ans[i]<<" ";
}