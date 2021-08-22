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


//Similar Question (using swap sort)
/*Given an array, arr[] of N elements such that 
every element of the array is an integer in the range 1 to n, 
the task is to find the sum of all the distinct elements of the array.

Input: N = 9  arr[] = {5, 1, 2, 4, 6, 7, 3, 6, 7}
Output: 28
Explanation: The distinct elements in the array are 1, 2, 3, 4, 5, 6, 7.

Input: N = 3, arr[] = {1, 1, 1}
Output: 1

Time Complexity: O(N).
Auxiliary Space: O(1).      */

class Solution{
public:
    int sumOfDistinct(int arr[], int n) 
    {
        int i=0;
        while(i < n)
        {
            if(arr[i] != arr[arr[i]-1])
            {
                swap(arr[i], arr[arr[i]-1]);
            }
            else
            {
                i++;
            }
        }
        
        int distinctEleSum = 0;
        for(int i=0; i<n; i++)
        {
            if(arr[i]-1 == i) //all unique elements, at their ideal indices 
            {
                distinctEleSum += arr[i];
            }
            //if(arr[i]-1 != i)
            //i+1 = missing  and  arr[i] = duplicate
        }
        return distinctEleSum;
    } 
};