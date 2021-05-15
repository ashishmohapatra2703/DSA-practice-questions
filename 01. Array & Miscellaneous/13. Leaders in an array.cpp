// An element of array is leader if it is greater than or equal to all the elements to its right side.
// Also, the rightmost element is always a leader. 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> LeadersinArray(vector<int> arr, int n) 
{
    vector<int> v;
    v.push_back(arr[n-1]);
    
    int MaxOnRight = 0; //Max on the right from (i+1)th index to end
    for(int i=n-2; i>=0; i--)
    {
        MaxOnRight = max(MaxOnRight, arr[i+1]);
        if(arr[i] >= MaxOnRight)
        {
            v.push_back(arr[i]);
        }
    }
    reverse(v.begin() , v.end());
    return v;
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
            
        vector<int> ans = LeadersinArray(arr, n);
        for(int x: ans)
            cout<<x<<" ";
        cout<<endl;
    }
}
/*
Example:
Input:
    3
    6
    16 17 4 3 5 2
    5
    1 2 3 4 0
    5
    7 4 5 7 3
Output:
    17 5 2
    4 0
    7 7 3
*/