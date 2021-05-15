/* Given an array A[] of integers, sort the array according to frequency of elements.
That is elements that have higher frequency come first. 
If frequencies of two elements are same, then smaller number comes first.
Input : arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output : arr[] = {8, 8, 8, 2, 2, 5, 5, 6}    */

//M-1 O(n.logn) //hashing + sorting of 2-D vector used
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

bool sortfreq(pair<int, int> &a, pair<int, int> &b) 
{
    if (a.first == b.first)  
        return a.second < b.second;  //If frequency is same then sort by element 
          
    return a.first > b.first;  //higher frequency come first
}
void FrequencySort(vector<int> arr, int n) 
{
    unordered_map<int,int> mp; 
    for (int i=0; i<n; i++)
    {
        mp[arr[i]] ++;    //ele <=> freq
    }

    vector<pair<int, int> > v; 
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        v.push_back({it->second , it->first}); // {freq , ele}
    }
    sort(v.begin() , v.end() , sortfreq); //comparator function used

    //printing freq.sort o/p array
    for(int i=0; i<v.size(); i++) 
    {
        while(v[i].first--)
        {
            cout<< v[i].second <<" ";  
        }
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        
        FrequencySort(arr, n);
        cout<<endl;
    }
}


////// M-2  //Hashing + Heap used
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class myComparator
{
public:
    int operator()(pair<int, int> &a, pair<int, int> &b) 
    {
        if (a.first == b.first)  
            return a.second > b.second;  //If frequency is same then sort by element 
          
        return a.first < b.first; 
    } //a is down , b is top
};

void FrequencySort(vector<int> arr, int n) 
{
    unordered_map<int,int> mp; 
    for (int i=0; i<n; i++)
    {
        mp[arr[i]] ++;    //ele <=> freq
    }
    
    priority_queue<pair<int,int>, vector<pair<int,int>>, myComparator> maxh;
    for(auto it=mp.begin(); it!=mp.end(); it++)
    {
        maxh.push({it->second , it->first});   // {freq , ele}
    }
    
    //printing freq.sort o/p array
    while(! maxh.empty())
    {
        for(int i=0; i < maxh.top().first ; i++)  
        {
            cout << maxh.top().second <<" ";  
        }
        maxh.pop();
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> arr(n);
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        
        FrequencySort(arr, n);
        cout<<endl;
    }
}