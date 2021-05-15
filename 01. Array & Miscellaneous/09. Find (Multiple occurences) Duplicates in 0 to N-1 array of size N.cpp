/*Given an array a[] of size N which contains elements from 0 to N-1, 
you need to find all the elements occurring more than once in the given array.

Input:  N = 5
        a[] = {2,3,1,2,3}
Output: 2 3 
Explanation: 2 and 3 occur more than once
in the given array. */

#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
vector<int> duplicates(int a[], int n) 
{
    int i=0;
    while(i < n)
    {
        if(a[i] != a[a[i]])
            swap(a[i] , a[a[i]]);
        else
            i++;
    }
    
    unordered_set<int> dupt; 
    for(int i=0; i<n; i++)
    {
        if(a[i] != i)
            dupt.insert(a[i]);
    }
    
    vector<int> ans;
    for(int x : dupt)
        ans.push_back(x);

    if(ans.size() == 0)
        ans.push_back(-1);
    sort(ans.begin(), ans.end());
    
    return ans;
}

int main() 
{
    int t;
    cin >> t;
    while (t-- ) 
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) 
            cin >> a[i];
            
        vector<int> ans = duplicates(a, n);
        for (int i : ans) 
            cout << i << " ";
            
        cout<<endl;
    }
    return 0;
}
