//Given an array of positive integers of size N. 
//The task is to make a sorted array which will contain all distinct digits present in A.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> GetDistinctElements(vector<int> A) 
{
    vector<int> distinctA;
    
    int n = A.size();
    for(int i=0; i<n; i++)
    {
        int count=1;
        for(int j=0; j<i; j++)
        {
            if(A[i]==A[j])
            {
                count++;
                break;
            }
        }
        if(count==1)
            distinctA.push_back(A[i]);
    }
    sort(distinctA.begin(), distinctA.end());
    return distinctA;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr[n];
        for (int i=0; i<n; i++) 
            cin>>arr[i];
        
        vector<int> A;
        for (int i=0; i<n; i++)
        {
            for(int j=0; j<arr[i].size(); j++)
            {
                A.push_back(arr[i][j]-'0');
            }
        }
            
        vector<int> result = GetDistinctElements(A);
        for(int i=0; i<result.size(); i++)
            cout<<result[i]<<" ";
        cout<<endl;
    }
}
// arr:    111 222 333 446
// A:      1 1 1 2 2 2 3 3 3 4 4 6 
//result:  1 2 3 4 6 